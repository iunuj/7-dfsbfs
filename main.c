#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool visited[MAX];  

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        return;
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int item;
    if (q->front == -1) {
        return -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

void bfs_iterative(int graph[MAX][MAX], int start, int target, int num_nodes) {
    struct Queue q;
    q.front = q.rear = -1; 

    enqueue(&q, start);
    visited[start] = true;

    int visit_count = 0; 

    while (q.front != -1) {
        int node = dequeue(&q);
        printf("%d ", node);  
        visit_count++;

        if (node == target) {
            printf("\nŽ�� ����: %d\n", target);
            printf("�湮�� ����� ��: %d\n", visit_count);
            return;
        }

        for (int i = 0; i < num_nodes; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(&q, i);
                visited[i] = true;
            }
        }
    }

    printf("\nŽ�� ����\n");
    printf("�湮�� ����� ��: %d\n", visit_count);
}

void dfs_iterative(int graph[MAX][MAX], int start, int target, int num_nodes) {
    int stack[MAX];
    int top = -1;  
    stack[++top] = start; 
    visited[start] = true;  

    int visit_count = 0; 

    while (top != -1) {
        int node = stack[top--];  
        printf("%d ", node);  
        visit_count++;

        if (node == target) {
            printf("\nŽ�� ����: %d\n", target);
            printf("�湮�� ����� ��: %d\n", visit_count);
            return;
        }

        for (int i = 0; i < num_nodes; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                stack[++top] = i; 
                visited[i] = true;  
            }
        }
    }

    printf("\nŽ�� ����\n");
    printf("�湮�� ����� ��: %d\n", visit_count);
}

void runUserInterface(int graph[MAX][MAX]) {
    int choice;
    int start_node, target_node;

    printf("------------------------\n");
    printf("1 : ���� �켱 Ž��\n");
    printf("2 : �ʺ� �켱 Ž��\n");
    printf("3 : ����\n");
    printf("------------------------\n");

    while (1) {
        printf("�޴� �Է�: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }

        printf("���� ��ȣ�� Ž���� �� �Է�: ");
        scanf("%d %d", &start_node, &target_node);

        for (int i = 0; i < MAX; i++) {
            visited[i] = false;
        }

        if (choice == 1) {
            dfs_iterative(graph, start_node, target_node, MAX);
        }
        else if (choice == 2) {
            bfs_iterative(graph, start_node, target_node, MAX);
        }
        else {
            printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
        }
    }
}

int main() {
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
    };

    runUserInterface(graph); 
    return 0;
}
