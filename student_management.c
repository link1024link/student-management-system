#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// 生徒構造体
typedef struct {
    int id;
    char name[50];
    int age;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// 初期データを登録
void initializeStudents() {
    students[0].id = 1001;
    strcpy(students[0].name, "山田太郎");
    students[0].age = 20;
    
    students[1].id = 1002;
    strcpy(students[1].name, "田中花子");
    students[1].age = 21;
    
    students[2].id = 1003;
    strcpy(students[2].name, "佐藤次郎");
    students[2].age = 20;
    
    studentCount = 3;
    printf("初期データを登録しました。\n");
}

// 生徒追加
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("これ以上登録できません。\n");
        return;
    }

    Student *s = &students[studentCount];
    char buf[256];

    printf("学籍番号: ");
    scanf("%d", &s->id);

    // 入力バッファをクリア
    fgets(buf, sizeof(buf), stdin);

    printf("名前: ");
    fgets(s->name, sizeof(s->name), stdin);
    // 改行文字を削除
    s->name[strcspn(s->name, "\n")] = '\0';

    printf("年齢: ");
    scanf("%d", &s->age);

    studentCount++;
    printf("登録完了しました。\n");
}

// 一覧表示
void showStudents() {
    if (studentCount == 0) {
        printf("登録データがありません。\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d | 名前: %s | 年齢: %d\n",
               students[i].id,
               students[i].name,
               students[i].age);
    }
}

// ID検索
void searchStudent() {
    int searchId;
    char buf[256];
    printf("検索する学籍番号: ");
    scanf("%d", &searchId);
    // 入力バッファをクリア
    fgets(buf, sizeof(buf), stdin);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchId) {
            printf("見つかりました → 名前: %s 年齢: %d\n",
                   students[i].name,
                   students[i].age);
            return;
        }
    }

    printf("該当するデータがありません。\n");
}

int main() {
    int choice;
    char buf[256];

    // 初期データを登録
    initializeStudents();

    while (1) {
        printf("\n--- 生徒管理システム ---\n");
        printf("1. 一覧表示\n");
        printf("2. 生徒追加\n");
        printf("3. ID検索\n");
        printf("0. 終了\n");
        printf("選択: ");
        scanf("%d", &choice);
        // 入力バッファをクリア
        fgets(buf, sizeof(buf), stdin);

        switch (choice) {
            case 1:
                showStudents();
                break;
            case 2:
                addStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 0:
                printf("終了します。\n");
                return 0;
            default:
                printf("無効な入力です。\n");
        }
    }

    return 0;
}