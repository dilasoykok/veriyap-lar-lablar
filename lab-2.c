#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 2110205006 Dila Soykök
// Random üretilmiş yüz sayıyı küçükten büyüğe sıralama kodu
// Bağlı liste yapısı
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node;

// Yeni bir düğüm (node) oluşturma fonksiyonu
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Bellek yetersiz.");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Bağlı listeye eleman ekleyen fonksiyon
node* insertSorted(node* head, int data) {
    node* newNode = createNode(data);
    
    // Liste boşsa veya yeni eleman ilk elemandan küçükse
    if (head == NULL || data < head->data) {
        newNode->next = head;
        head = newNode;
    }
    else {
        node* current = head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    
    return head;
}

// Bağlı listeyi ekrana yazdıran fonksiyon
void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    srand(time(NULL)); // Rastgele sayıları farklı her çalıştırmada elde etmek için kullanılır.
    node* head = NULL; // Bağlı listenin başlangıcı

    // 100 rastgele sayı üretip listeye ekliyoruz
    for (int i = 0; i < 100; i++) {
        int randomNum = rand() % 1000; // 0 ile 999 arasında rastgele sayı üretiyoruz
        head = insertSorted(head, randomNum);
    }

    // Sıralı liste çıktısını ekrana yazdırıyoruz
    printList(head);

    return 0;
}
