//
//  Ahocorasick.hpp
//  coding_pac
//
//  Created by Edgar Wong on 08/01/2023.
//

#ifndef Ahocorasick_hpp
#define Ahocorasick_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#define MaxState 500
#define EngWords 26
class AC{
private:
	int OccurenceOfWords[MaxState];
	int failureLink[MaxState];
	int GotoFunction[MaxState][EngWords];
public:
	int BuildMatchingMachine(const vector<string>& word){
		memset(OccurenceOfWords, 0, sizeof(OccurenceOfWords));
		memset(failureLink, -1, sizeof(failureLink));
		memset(GotoFunction, -1, sizeof(GotoFunction));
		int states = 1;
		//build a trie using arr
		for(int i = 0; i< word.size(); i++){
			const string &keyword = word[i];
			int currentState = 0;
			for(int j = 0; j< keyword.size(); j++){
				int index = keyword[j] - 'a';
				if(GotoFunction[currentState][index] == -1){
					GotoFunction[currentState][index] = states++;
				}
				currentState = GotoFunction[currentState][index];
			}
			OccurenceOfWords[currentState] |=(1 << i);
		}
		for(int i = 0; i< EngWords; i++){
			if(GotoFunction[0][i] == -1){
				GotoFunction[0][i] = 0;
			}
		}
		
		//build failure Link
		queue<int> q;
		for(int i = 0; i < EngWords; i++){
			if(GotoFunction[0][i] != 0 && GotoFunction[0][i] != -1){
				failureLink[GotoFunction[0][i]] = 0;
				q.push(GotoFunction[0][i]);
			}
		}
		
		while (!q.empty()) {
			int state = q.front();
			q.pop();
			for(int i = 0; i<= EngWords; i++){
				if(GotoFunction[state][i] != -1){
					int failure = failureLink[state];
					while (GotoFunction[failure][i] == -1) {
						failure = failureLink[failure];
					}
					failure = GotoFunction[failure][i];
					failureLink[GotoFunction[state][i]] = failure;
					OccurenceOfWords[GotoFunction[state][i]] |= OccurenceOfWords[failure];
					q.push(GotoFunction[state][i]);
				}
			}
		}
		return states;
	}
	
	int FindNextState(int currentState, char nextInput){
		int ans = currentState;
		int c = nextInput - 'a';
		while (GotoFunction[ans][c] == -1) {
			ans = failureLink[ans];
		}
		return GotoFunction[ans][c];
	}
	
	void searchWords(const vector<string>& arr, string text){
		BuildMatchingMachine(arr);
		int currentState = 0;
		for(int i = 0; i<text.size(); i++){
			currentState = FindNextState(currentState, text[i]);
			if(OccurenceOfWords[currentState] == 0){
				continue;
			}
			for(int j = 0; j < arr.size(); j++){
				if(OccurenceOfWords[currentState] & (1 << j)){
					cout<<"Find it\n";
				}
			}
		}
	}
};


#endif /* Ahocorasick_hpp */
