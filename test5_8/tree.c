#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct file {
    char name[MAX_NAME_LENGTH];
    struct file *parent;
    struct file *children;
};

// 创建一个新的文件
struct file *create_file(char *name) {
    struct file *new_file = malloc(sizeof(struct file));
    strncpy(new_file->name, name, MAX_NAME_LENGTH);
    new_file->parent = NULL;
    new_file->children = NULL;
    return new_file;
}

// 在指定目录下创建一个新的子目录
void create_directory(struct file *parent, char *name) {
    struct file *new_directory = create_file(name);
    new_directory->parent = parent;
    if (parent->children == NULL) {
        parent->children = new_directory;
    } else {
        struct file *current = parent->children;
        while (current->children != NULL) {
            current = current->children;
        }
        current->children = new_directory;
    }
}

// 在指定目录下创建一个新的文件
void create_file_in_directory(struct file *parent, char *name) {
    struct file *new_file = create_file(name);
    new_file->parent = parent;
    if (parent->children == NULL) {
        parent->children = new_file;
    } else {
        struct file *current = parent->children;
        while (current->children != NULL) {
            current = current->children;
        }
        current->children = new_file;
    }
}

// 打印文件树
void print_tree(struct file *root, int level) {
    int i;
    for (i = 0; i < level; i++) {
        printf("-");
    }
    printf("%s\n", root->name);
    struct file *current = root->children;
    while (current != NULL) {
        print_tree(current, level + 1);
        current = current->children;
    }
}

int main() {
    struct file *root = create_file("/");
    create_directory(root, "home");
    create_directory(root, "usr");
    struct file *home_directory = root->children;
    create_directory(home_directory, "user");
    create_file_in_directory(home_directory, "document.txt");
    create_file_in_directory(home_directory, "picture.png");
    create_file_in_directory(home_directory, "music.mp3");
    print_tree(root, 0);
    return 0;
}
