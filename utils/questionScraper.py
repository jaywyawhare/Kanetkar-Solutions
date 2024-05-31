import os
import re
import json

def get_questions():
    root_dir = '.'  
    questions_dict = {}

    for root, dirs, files in os.walk(root_dir):
        chapter_match = re.search(r'Chapter-(\d+)', root)
        if chapter_match:
            chapter_number = chapter_match.group(1)
            chapter_key = f"Chapter {chapter_number}"
            if chapter_key not in questions_dict:
                questions_dict[chapter_key] = []

            for file in files:
                if file.endswith('.c'):
                    file_path = os.path.join(root, file)
                    with open(file_path, 'r') as f:
                        lines = f.readlines()
                        
                    question_lines = []
                    for line in lines:
                        if '#include' in line:
                            break
                        question_lines.append(line.strip())
                    
                    question = ' '.join(question_lines).strip()
                    if question:
                        question_number = re.search(r'q(\d+)\.c', file).group(1)
                        question_entry = {
                            "Question Number": f"Question {question_number}",
                            "Question": question,
                            "Folder": root,
                            "File": file
                        }
                        questions_dict[chapter_key].append(question_entry)

    questions_dict = {k: v for k, v in questions_dict.items() if v}
    questions_dict = dict(sorted(questions_dict.items(), key=lambda x: int(x[0].split(' ')[1])))
    
    return questions_dict

if __name__ == "__main__":
    questions = get_questions()
    with open('questions.json', 'w') as json_file:
        json.dump(questions, json_file, indent=4)
