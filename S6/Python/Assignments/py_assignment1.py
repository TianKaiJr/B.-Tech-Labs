import requests
from collections import Counter

class req_functions():
    def averageWordLength(text):
        words=text.split()
        Tlen=sum(len(word) for word in words)
        if len(words)==0:
            return 0
        else:
            return Tlen/len(words)

    def modeT3(text):
        words=text.split()
        count=Counter(words)
        return count.most_common(3)
    
    def synonymAPI(word):
        url=f"https://api.datamuse.com/words?rel_syn={word}"
        response=requests.get(url)
        if response.status_code==200:
            data=response.json()
            return [item['word'] for item in data]
        else:
            print("Failed Retrieval\n")
            return []
        
    def wordReplaceSuggest(textR,overusedW):
        suggestions={}
        for wordx in overusedW:
            synonyms=req_functions.synonymAPI(wordx)
            if synonyms:
                suggestions[wordx]=synonyms[0]
            else:
                suggestions[wordx]="NO REPLACEMENTS"
        return suggestions
    
print('\nAVERAGE WORD LENGTH FINDER\n')
text=input("String >> ")
avgLen=req_functions.averageWordLength(text)
print("Average Word Length = ", avgLen)

print('\nTOP THREE FREQUENT WORDS FINDER\n')
text=input("String >> ")
for word,count in req_functions.modeT3(text):
    print(f"{word} :: {count}")

print('\nREPLACEMENT SUGGESTOR\n')
textS=input("String >> ")
wordS=input("Overused Words List >> ")
overusedList=wordS.split()
replaceW=req_functions.wordReplaceSuggest(textS,overusedList)
for wordR,replaceW in replaceW.items():
    print(f"{wordR} >>> {replaceW}")
