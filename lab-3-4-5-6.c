#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 2110205006 Dila Soykök
//Bir listedeki öğrencilerin Ad yaş ve numaralarının tutulduğu ve istenilen zamanda bakılıp değiştirilip, yazdırılabildiği ve en uzun ismi bulma fonksiyonu
// kodun başlangıcı
struct School {
    int no;
    int age;
    char name[40];
    struct School* next;
};

typedef struct School node;
node* head, * prev, * newMode, * locate;

node* Creating_list() {
    int i, N;
    node* p;
    p = head;
    printf("Please enter N: ");
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        if (i == 0) {
            head = (node*)malloc(sizeof(node));
            p = head;
        }
        else {
            p->next = (node*)malloc(sizeof(node));
            p = p->next;
        }
        printf("StudentNo: ");
        scanf("%d", &p->no);
        printf("Age: ");
        scanf("%d", &p->age);
        printf("Student name: ");
        scanf("%s", p->name);
    }
    p->next = NULL;
    return head;
}

node* AddingList() {
    int N;
    node* p, * q;
    newMode = (node*)malloc(sizeof(node));
    printf("Enter an N number to add: ");
    scanf("%d", &N);
    printf("StudentNo: ");
    scanf("%d", &newMode->no);
    printf("Age: ");
    scanf("%d", &newMode->age);
    printf("Student name: ");
    scanf("%s", newMode->name);
    p = head;
    if (p->no == N) { // İlk düğümü kontrol et  N sayısında mı diye
        newMode->next = p; // Yeni bir düğüm oluştur 
        head = newMode; // Yeni düğümü başlangıç düğümüne atama
    }
    else {
        while (p->next != NULL && p->no != N) { // Döngü verilen N sayısı bulunana kadar devam eder
            q = p; // Önceki düğümü sakla
            p = p->next; // Yeni düğüme geçis
        }
        if (p->no == N) { // Eğer N sayısı bulunmuşsa
            q->next = newMode; // Önceki düğümün sonraki işaretçisini yeni düğüme ayarla
            newMode->next = p; // Yeni düğümün sonraki işaretçisini bulunan düğüme ayarla
        }
        else if (p->next == NULL) { // Eğer yeterli sayıya ulaşılmışsa
            p->next = newMode; // Son düğümün sonraki işaretçisini yeni düğüme ayarla
            newMode->next = NULL; // Yeni düğümün bir sonraki sorunlarını listedeki son düğümlemeyen NULL olarak ayarlayın
        }
    }
    return head;
}



// Yazdırma fonksiyonu
void Printing_in_the_list() {
    int counter = 1; // Sayaç başlangıcı 1
    node* p; // Düğüm işaret başlangıcı
    p = head; // başlangıçı düğümünü p ye atama
    while (p != NULL) { // Listeyi yineleyin
        printf("%d-%s %d %d\t", counter, p->name, p->age, p->no); // düğüm verisini yazdırma
        counter++; // Sayacı arttırma
        p = p->next; // Yeni düğüme hareket etme
    }
    printf("\n"); // Yeni satıra yazdırma
}

// Bağlı listeden düğüm silme fonksiyonu
node* Deletinglist() {
    node* p, * q;
    int N;

    //Silinecek öğrenci sayısı için kullanıcı girişi alma
    printf("N: ");
    scanf("%d", &N);

    // İlk düğümün giriş numarasıyla eşleşip eşleşmediğini kontrol etme
    p = head;
    if (p->no == N) {
        head = p->next; // Düğümün baş pointera aktarılması
        free(p); // Silinen düğümün belleğini boşaltın
    }
    else {
        // Düğümü bulana veya sonuna ulaşana kadar listeyi yineleyin
        while (p->next != NULL && p->no != N) {
            q = p; // Önceki düğümü saklama
            p = p->next; // Yeni düğüme geçiş
        }

        // Eğer bulunmadıysa kontrol et
        if (p->no == N) {
            q->next = p->next; // Önceki pointeri yeni pointera aktarılışı
            free(p); // Silinen düğümün belleğini boşaltın
        }
        else if (p->next == NULL) {
            printf("There is no student found to delete.\n");
        }
    }

    return head;
}
node* Walking_in_the_list() {
    locate = NULL;
    int key;
    printf("Enter a student number to locate: ");
    scanf("%d", &key);
    while (head != NULL) {
        if (head->no != key) {
            head = head->next;
        }
        else {
            locate = head;
            break;
        }
    }
    return locate;
}

// En uzun isim bulma fonksiyonu 
void The_Longest_Name() {
    // En uzun adı ve öğrenci adı değişkenlerini oluşturma
    int longestName = 0;
    char longestNameStudent[50];

    // listenin başlangıç yeri
    node* p = head;

    // Iterate through the list
    while (p != NULL) {
        // Mevcut öğrencinin adı şu ana kadar bulunan en uzun addan uzunsa
        if (strlen(p->name) > longestName) {
            //En uzun adı güncelleyin ve en uzun adı öğrencinin adını saklama
            longestName = strlen(p->name);
            strcpy(longestNameStudent, p->name);
        }

        // Öğrenciden öğrenciye geçiş
        p = p->next;
    }

    // IEğer en uzun isim bulunduysa
    if (longestName > 0) {
        // En uzun ismi yazdırma
        printf("The longest name is %s\n", longestNameStudent);
    }
    else {
        // Eğer liste boşsa yazdırma işlemi
        printf("The list is empty.\n");
    }
}//main fonksiyon
int main() {
    printf("Welcome to the list\n");
    printf("Choose one operation\n");
    printf("1-Creating list\n2-Adding list\n3-Walking in the list\n4-Printing the list\n5-Deleting list\n6-Find the longest name\n");

    int operation;
    printf("Choose the option:");
    scanf("%d", &operation);

    switch (operation) {
        case 1:
            head = Creating_list();
            
        case 2:
            AddingList();
            
        case 3:
            Walking_in_the_list();
            
        case 4:
            Printing_in_the_list();
            
        case 5:
            Deletinglist();
           
        case 6:
            The_Longest_Name();
            
        default:
            printf("Invalid Operation\n");
            
    }

    return 0;
}
