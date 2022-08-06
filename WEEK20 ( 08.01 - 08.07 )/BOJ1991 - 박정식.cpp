#pragma warning(disable:4996)
#include <iostream>
#include <map>

#define MAX 26

using namespace std;

struct Node
{
	char left;
	char right;
};


// 맵으로 트리 구현
map<char, Node> m;

void preOrder(char node) { // 전위 순회
	// root - left - right
	if (node == '.') return;

	printf("%c", node);
	preOrder(m[node].left);
	preOrder(m[node].right);
}

void inOrder(char node) { // 중위 순회
	// left - root - right
	if (node == '.') return;

	inOrder(m[node].left);
	printf("%c", node);
	inOrder(m[node].right);
}

void postOrder(char node) { // 후위 순회
	// left - right - root
	if (node == '.') return;

	postOrder(m[node].left);
	postOrder(m[node].right);
	printf("%c", node);
}

int main() 
{
	int n;
	scanf("%d", &n);

	char node, left, right;
	// 트리 입력받기
	for (int i = 0; i < n; i++) 
	{
		cin >> node >> left >> right;
		m[node].left = left;
		m[node].right = right;
	}

	preOrder('A');
	printf("\n");

	inOrder('A');
	printf("\n");

	postOrder('A');

	return 0;
}