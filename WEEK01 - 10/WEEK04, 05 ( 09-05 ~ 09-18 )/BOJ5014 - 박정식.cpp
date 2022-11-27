#define MAX 1000000 + 1
#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int visit[MAX];

int main()
{
	// F : �������, S : ��ȣ��ġ(������), G : ��ǥ��, U : UP��ư�� ������ ���� �ö󰡴� ����, D : Down��ư�� ������ ���� �������� ����
	cin >> F >> S >> G >> U >> D;
	
	// �������� �������̶�� �ٷ� ����������.
	if (S == G)
	{
		cout << 0 << endl;
		return 0;
	}

	// ť���� �ϰ� �������� q�� �־ ���������� Ž���ϱ�
	queue<int> q;
	q.push(S);
	visit[S] = 1;

	// ť�� ���̻� ���Ұ� ������ ���� Ž���ϱ�
	while (!q.empty())
	{
		// cur = ������
		// ť���� �����͸� �ϳ��� ������ ������ ��ġ �ٲٱ�
		int cur = q.front();
		q.pop();
		// ��ǥ���� ������ �ߴٸ�
		if (cur == G)
			break;
		
		// ���� ������ ���� ���� �ö󰡺���
		int nextFloor = cur + U;
		// visit�迭�� 0�� �ִٸ� �湮���� ���� �����Դϴ�.
		// ������������ ������� ���Ͽ����ϰ� �湮 ���� �ʾҴٸ� if�� ����
		if (nextFloor <= F && visit[nextFloor] == 0)
		{
			// ť�� ����Ž�� ������� ����ֱ�
			q.push(nextFloor);
			// �湮üũ�� ������ �ɸ��� �ð��� ǥ���ϱ� ���� 1�� �����ֱ�
			visit[nextFloor] = visit[cur] + 1;			
		}

		// ���� �������� �Ʒ��ε� ����������
		nextFloor = cur - D;		
		// visit�迭�� 0�� �ִٸ� �湮���� ���� �����Դϴ�.
		// ������������ 0�� �̻��̿����ϰ� �湮 ���� �ʾҴٸ� if�� ����
		if (nextFloor >= 1 && visit[nextFloor] == 0)
		{
			// ť�� ����Ž�� ������� ����ֱ�
			q.push(nextFloor);
			// �湮üũ�� ������ �ɸ��� �ð��� ǥ���ϱ� ���� 1�� �����ֱ�
			visit[nextFloor] = visit[cur] + 1;			
		}
	}

	// �����Ҷ� 1�� �����ְ� �����ϴϱ� 1���� �湮�ѽð� ������ֱ�
	if (visit[G] != 0)
		cout << visit[G]-1 << endl;
	// ��� Ž���� ���ƴµ��� ��������� �湮���� �ʾҴٸ� ������ֱ�
	else
		cout << "use the stairs" << endl;

	return 0;
}