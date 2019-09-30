#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> answer;
vector<vector<vector<float>>> num(10, vector<vector<float>>(7, vector<float>(5, 0)));
vector<vector<float>> W(4, vector<float>(35, 0.5));
float n = 1;
int threshold = 0.1;

void setNumber();
bool learning(vector<int>, vector<int>);
void checking(vector<int>);
void setAnswer(vector<int> v) {
	if (v.size() == 4) {
		answer.push_back(v);
		return;
	}
	v.push_back(-1);
	setAnswer(v);
	v.pop_back();
	v.push_back(1);
	setAnswer(v);
	v.pop_back();
}


int main() {
	
	vector<int> v;
	setAnswer(v);
	/*int a = 0;
	for (auto i : answer) {
		cout << a << ": ";
		for(auto j : i)
			cout << j << " ";
		cout << endl;
		a++;
	}*/
	setNumber();
	
	vector<int> tmpV(35);
	
	while (1) {
		int correctCount = 0;
		for (int a = 0; a <= 9; a++) {
			int idx = 0;
			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 5; j++) {
					tmpV[idx++] = num[a][i][j];
				}
			}
			bool correctFlag = learning(tmpV, answer[a]);
			
			if (correctFlag) {
				correctCount++;
			}
		}
		if (correctCount == 10) {
			break;
		}
	}
	/*for (auto i : W) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}*/
	vector<vector<int>> sample(7, vector<int>(5));
	//2
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (b == 0 || b == 3 || b == 6) {
				sample[b][a] = 1;
			}
			else if (a == 4 && b <= 3) {
				sample[b][a] = 1;
			}
			else if (a == 0 && b > 3) {
				sample[b][a] = 1;
			}
		}
	}
	// sample[1][0] = 1;
	// sample[2][0] = 1;
	sample[5][4] = 1;
	sample[6][0] = 0;
	int idx = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			tmpV[idx++] = sample[i][j];
		}
	}

	for (auto j : sample) {
		for (auto x : j) {
			cout << x;
		}
		cout << endl;
	}
	cout << endl;
	checking(tmpV);

	return 0;
}
void setNumber() {
	// 0
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (b == 0 || b == 6) {
				num[0][b][a] = 1;
			}
			else if (a == 4 || a == 0) {
				num[0][b][a] = 1;
			}
		}
	}
	//1
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (a == 4) {
				num[1][b][a] = 1;
			}
		}
	}
	//2
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (b == 0 || b == 3 || b == 6) {
				num[2][b][a] = 1;
			}
			else if (a == 4 && b <= 3) {
				num[2][b][a] = 1;
			}
			else if (a == 0 && b > 3) {
				num[2][b][a] = 1;
			}
		}
	}
	//3
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (b == 0 || b == 3 || b == 6) {
				num[3][b][a] = 1;
			}
			else if (a == 4) {
				num[3][b][a] = 1;
			}
		}
	}
	//4
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (b == 3) {
				num[4][b][a] = 1;
			}
			else if (a == 3) {
				num[4][b][a] = 1;
			}
			else if (a == 0 && b < 3) {
				num[4][b][a] = 1;
			}
			else if (a == 3 && b < 3) {
				num[4][b][a] = 1;
			}
		}
	}
	//5
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (b == 0 || b == 6 || b == 3) {
				num[5][b][a] = 1;
			}
			else if (a == 0 && b < 3) {
				num[5][b][a] = 1;
			}
			else if (a == 4 && b > 3) {
				num[5][b][a] = 1;
			}
		}
	}
	//6
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (a == 0) {
				num[6][b][a] = 1;
			}
			else if (b == 6 || b == 3) {
				num[6][b][a] = 1;
			}
			else if (a == 4 && b > 3) {
				num[6][b][a] = 1;
			}
		}
	}
	//7
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (a == 4) {
				num[7][b][a] = 1;
			}
			else if (b == 0) {
				num[7][b][a] = 1;
			}
		}
	}
	//8
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (b == 0 || b == 6 || b == 3) {
				num[8][b][a] = 1;
			}
			else if (a == 4 || a == 0) {
				num[8][b][a] = 1;
			}
		}
	}
	//9
	for (int a = 0; a < 5; a++) {
		for (int b = 0; b < 7; b++) {
			if (b == 3 || b == 0) {
				num[9][b][a] = 1;
			}
			else if (a == 4) {
				num[9][b][a] = 1;
			}
			else if (a == 0 && b < 3) {
				num[9][b][a] = 1;
			}
			else if (a == 4 && b < 3) {
				num[9][b][a] = 1;
			}
		}
	}
}
void checking(vector<int> sampleV) {
	vector<int> tmpAnswer(4);
	for (int i = 0; i < 4; i++) {
		int tmpSum = 0;
		for (int j = 0; j < 35; j++) {
			tmpSum += sampleV[j] * W[i][j];
		}
		if (tmpSum >= threshold) tmpAnswer[i] = 1;
		else tmpAnswer[i] = -1;
	}
	
	for (int j = 0; j < 10; j++) {
		int tmpCount = 0;
		for (int i = 0; i < 4; i++) {
			if (tmpAnswer[i] == answer[j][i]) tmpCount++;
		}
		if (tmpCount == 4) {
			cout << "answer: " << j << endl;
			return;
		}
	}
	cout << "no matching" << endl;
	return;
}



bool learning(vector<int> numV, vector<int> answerV) {
	vector<int> tmpAnswer(4);
	for (int i = 0; i < 4; i++) {
		int tmpSum = 0;
		for (int j = 0; j < 35; j++) {
			tmpSum += numV[j] * W[i][j];
		}
		if (tmpSum >= threshold) tmpAnswer[i] = 1;
		else tmpAnswer[i] = -1;
	}

	int tmpCount = 0;
	for (int i = 0; i < 4; i++) {
		if (tmpAnswer[i] == answerV[i]) tmpCount++;
		else {
			for (int j = 0; j < 35; j++) {
				W[i][j] += n * (answerV[i] - tmpAnswer[i]) * numV[j];
			}
		}
	}
	if (tmpCount == 4) return true;
	else return false;
}
