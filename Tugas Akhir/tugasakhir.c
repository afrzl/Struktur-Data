#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

struct dob
{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct dob presentDate;

struct contact
{
    int _id;
    char name[100];
    struct dob dob;
    char sex;
    char no_telp[15];
    char email[50];

    struct contact *next;
};
typedef struct contact *ptrContact;

typedef struct
{
    int data[100];
    int front;
    int rear;
} Queue;

ptrContact head = NULL;
unsigned int countContact = 0;
int _id = 0;
int adj[100][100] = {0};

int calculateAge(ptrContact data)
{
    return presentDate.year - data->dob.year;
}

void printSinglyContact(ptrContact data, int i)
{
    printf("| #%d. No. Telp\t: %-29s |\n"
           "|     Nama\t: %-29s |\n"
           "|     Tgl Lahir\t: %02d-%02d-%-23d |\n"
           "|     Umur\t: %-29d |\n"
           "|     JK\t: %-29c |\n"
           "|     Email\t: %-29s |\n",
           data->_id,
           data->no_telp,
           data->name,
           data->dob.day, data->dob.month, data->dob.year,
           calculateAge(data),
           data->sex,
           data->email);
}

ptrContact insert(ptrContact newData)
{
    ptrContact tmp;
    if (head == NULL)
    {
        head = newData;
    }
    else
    {
        tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newData;
    }
    countContact++;
    return (head);
}

ptrContact copyNode(ptrContact data)
{
    ptrContact newNode = (ptrContact)malloc(sizeof(struct contact));

    newNode->_id = data->_id;
    strcpy(newNode->name, data->name);
    strcpy(newNode->no_telp, data->no_telp);
    newNode->dob = data->dob;
    newNode->sex = data->sex;
    strcpy(newNode->email, data->email);
    newNode->next = NULL;

    return newNode;
}

ptrContact searhchById(int _id)
{
    ptrContact tmp = head;
    while (tmp != NULL)
    {
        if (tmp->_id == _id)
            return copyNode(tmp);
        tmp = tmp->next;
    }

    return tmp;
}

ptrContact searchByTelp(char *no_telp)
{
    ptrContact tmp = head;
    while (tmp != NULL)
    {
        if (strcmp(no_telp, tmp->no_telp) == 0)
            return copyNode(tmp);
        tmp = tmp->next;
    }

    return tmp;
}

ptrContact searchByName(char *name)
{
    ptrContact result = NULL;
    ptrContact tmp = head;

    while (tmp != NULL)
    {
        if (strcmp(tmp->name, name) == 0)
        {
            if (result == NULL)
                result = copyNode(tmp);
            else
            {
                ptrContact tmp_res = result;
                while (tmp_res->next != NULL)
                    tmp_res = tmp_res->next;
                tmp_res->next = copyNode(tmp);
            }
        }
        tmp = tmp->next;
    }

    return result;
}

int minMaxAge(bool min)
{
    ptrContact tmp = head;
    int minMax = 0;
    if (tmp != NULL)
    {
        minMax = calculateAge(tmp);
        while (tmp != NULL)
        {
            if ((calculateAge(tmp) < minMax && min) || (calculateAge(tmp) > minMax && !min))
            {
                minMax = calculateAge(tmp);
            }
            tmp = tmp->next;
        }
    }

    return minMax;
}

ptrContact searchByAge(int age)
{
    ptrContact result = NULL;
    ptrContact tmp = head;

    while (tmp != NULL)
    {
        if (calculateAge(tmp) == age)
        {
            if (result == NULL)
                result = copyNode(tmp);
            else
            {
                ptrContact tmp_res = result;
                while (tmp_res->next != NULL)
                    tmp_res = tmp_res->next;
                tmp_res->next = copyNode(tmp);
            }
        }
        tmp = tmp->next;
    }

    return result;
}

ptrContact searchByJK(char jk)
{
    ptrContact result = NULL;
    ptrContact tmp = head;

    while (tmp != NULL)
    {
        if (tmp->sex == jk)
        {
            if (result == NULL)
                result = copyNode(tmp);
            else
            {
                ptrContact tmp_res = result;
                while (tmp_res->next != NULL)
                    tmp_res = tmp_res->next;
                tmp_res->next = copyNode(tmp);
            }
        }
        tmp = tmp->next;
    }

    return result;
}

ptrContact searchByEmail(char *email)
{
    ptrContact result = NULL;
    ptrContact tmp = head;

    while (tmp != NULL)
    {
        if (strcmp(tmp->email, email) == 0)
        {
            if (result == NULL)
                result = copyNode(tmp);
            else
            {
                ptrContact tmp_res = result;
                while (tmp_res->next != NULL)
                    tmp_res = tmp_res->next;
                tmp_res->next = copyNode(tmp);
            }
        }
        tmp = tmp->next;
    }

    return result;
}

void createData()
{
    printf("\n=================================================\n"
           "|\t\tMENU TAMBAH KONTAK\t\t|\n"
           "-------------------------------------------------\n");
    ptrContact newData;
    newData = (ptrContact)malloc(sizeof(struct contact));

    do
    {
        printf(">> Masukkan Nomor Telepon: ");
        scanf(" %[^\n]s", newData->no_telp);

        if (searchByTelp(newData->no_telp) == NULL)
        {
            break;
        }
    } while (1);

    printf(">> Masukkan Nama: ");
    scanf(" %[^\n]s", newData->name);
    printf(">> Masukkan Tahun Lahir: ");
    scanf("%d", &newData->dob.year);
    do
    {
        printf(">> Masukkan Bulan Lahir: ");
        scanf("%d", &newData->dob.month);
        if (newData->dob.month <= 12)
            break;
    } while (1);
    do
    {
        printf(">> Masukkan Tanggal Lahir: ");
        scanf("%d", &newData->dob.day);
        if (newData->dob.day <= daysInMonth[newData->dob.month - 1] || (newData->dob.year % 4 == 0 && newData->dob.day <= 29))
            break;
    } while (1);
    printf(">> Masukkan Jenis Kelamin: ");
    scanf(" %c", &newData->sex);
    printf(">> Masukkan Email: ");
    scanf(" %[^\n]s", newData->email);
    newData->next = NULL;
    _id++;
    newData->_id = _id;

    head = insert(newData);
    printf("\n>> Data berhasil dibuat\n");
}

void searchData()
{
    printf("\n=================================================\n"
           "|\t\tMENU CARI KONTAK\t\t|\n"
           "-------------------------------------------------\n");
    char no_telp[15];
    int pilihan;

    printf("  Cari kontak berdasarkan: \n");
    printf("  [1] No. Telp\n"
           "  [2] Nama\n"
           "  [3] Umur\n"
           "  [4] JK\n"
           "  [5] Email\n"
           "  [0] Kembali\n");
    printf("  >> Masukkan pilihan: ");
    scanf("%d", &pilihan);
    ptrContact result;
    char string[50];
    int age = 0;

    if (pilihan >= 1 && pilihan <= 5)
    {
        switch (pilihan)
        {
        case 1:
            printf("\n>> Masukkan No Telp: ");
            scanf(" %[^\n]s", string);
            result = searchByTelp(string);
            break;

        case 2:
            printf("\n>> Masukkan Nama: ");
            scanf(" %[^\n]s", string);
            result = searchByName(string);
            break;

        case 3:
            printf("\n  Pilihan Umur: \n");
            printf("  [1] Maksimal\n"
                   "  [2] Minimal\n"
                   "  [3] Manual\n"
                   "  [0] Kembali\n");
            printf("  >> Masukkan pilihan: ");
            unsigned int pilihan_2;
            scanf("%d", &pilihan_2);
            if (pilihan_2 == 1)
                result = searchByAge(minMaxAge(false));
            else if (pilihan_2 == 2)
                result = searchByAge(minMaxAge(true));
            else if (pilihan_2 == 3)
            {
                printf("\n>> Masukkan Umur: ");
                scanf("%d", &age);
                result = searchByAge(age);
            }
            break;

        case 4:
            printf("\n>> Masukkan Jenis Kelamin: ");
            scanf(" %c", &age);
            result = searchByJK(age);
            break;

        case 5:
            printf("\n>> Masukkan Email: ");
            scanf(" %[^\n]s", string);
            result = searchByEmail(string);
            break;

        default:
            break;
        }
    }
    else if (pilihan == 0)
        return;

    if (result == NULL)
    {
        printf("Kontak tidak ditemukan.\n");
    }
    else
    {
        printf("\n-------------------------------------------------\n");
        printf("|\tKontak ditemukan dengan rincian :\t|\n");
        int i = 0;
        while (result != NULL)
        {
            i++;
            printf("-------------------------------------------------\n");
            printSinglyContact(result, i);
            result = result->next;
        }
        printf("=================================================\n");
    }
}

void editProcess(ptrContact newData)
{
    ptrContact tmp = head;
    while (tmp != NULL)
    {
        if (strcmp(tmp->no_telp, newData->no_telp) == 0)
        {
            strcpy(tmp->name, newData->name);
            tmp->dob = newData->dob;
            tmp->sex = newData->sex;
            strcpy(tmp->email, newData->email);
        }
        tmp = tmp->next;
    }
}

void editData()
{
    printf("\n=================================================\n"
           "|\t\tMENU EDIT KONTAK\t\t|\n"
           "-------------------------------------------------\n");
    char no_telp[15];
    printf(">> Masukkan Nomor Telepon : ");
    scanf("%s", no_telp);

    ptrContact result = searchByTelp(no_telp);

    if (result == NULL)
    {
        printf("Kontak tidak ditemukan.\n");
    }
    else
    {
        printf("\n-------------------------------------------------\n");
        printf("|\tKontak ditemukan dengan rincian :\t|\n");
        printSinglyContact(result, 1);
        printf("=================================================\n");
        ptrContact newData;
        newData = (ptrContact)malloc(sizeof(struct contact));

        printf(" Silahkan edit data, isikan 0 jika data tidak ingin diedit.\n");

        strcpy(newData->no_telp, result->no_telp);
        printf(">> Masukkan Nama: ");
        scanf(" %[^\n]s", newData->name);
        if (strcmp(newData->name, "0") == 0)
            strcpy(newData->name, result->name);

        printf(">> Masukkan Tahun Lahir: ");
        scanf("%d", &newData->dob.year);
        if (newData->dob.year == 0)
        {
            newData->dob.year = result->dob.year;
            newData->dob.month = result->dob.month;
            newData->dob.day = result->dob.day;
        }
        else
        {
            do
            {
                printf(">> Masukkan Bulan Lahir: ");
                scanf("%d", &newData->dob.month);
                if (newData->dob.month <= 12)
                    break;
            } while (1);
            do
            {
                printf(">> Masukkan Tanggal Lahir: ");
                scanf("%d", &newData->dob.day);
                if (newData->dob.day <= daysInMonth[newData->dob.month - 1] || (newData->dob.year % 4 == 0 && newData->dob.day <= 29))
                    break;
            } while (1);
        }

        printf(">> Masukkan Jenis Kelamin: ");
        scanf(" %c", &newData->sex);
        if (newData->sex == '0')
            newData->sex = result->sex;

        printf(">> Masukkan Email: ");
        scanf(" %[^\n]s", newData->email);
        if (strcmp(newData->email, "0") == 0)
            strcpy(newData->email, result->email);

        result = newData;
        editProcess(result);

        printf("\n  >> Kontak berhasil diubah.\n");
    }
}

int deleteProcess(char *no_telp)
{
    ptrContact temp = head, prev;

    if (temp != NULL && strcmp(temp->no_telp, no_telp) == 0)
    {
        head = temp->next;
        free(temp);
        return 0;
    }

    while (temp != NULL && strcmp(temp->no_telp, no_telp) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return -1;

    prev->next = temp->next;

    free(temp);
    countContact--;
    return 0;
}

void deleteData()
{
    printf("\n=================================================\n"
           "|\t\tMENU HAPUS KONTAK\t\t|\n"
           "-------------------------------------------------\n");
    char no_telp[15];
    printf(">> Masukkan Nomor Telepon yang Ingin Dihapus : ");
    scanf("%s", no_telp);

    if (deleteProcess(no_telp) == -1)
    {
        printf(">> Kontak tidak ditemukan.\n");
    }
    else
    {
        printf(">> Kontak berhasil dihapus.\n");
    }
}

void bersihkan_memori()
{
    while (head != NULL)
    {
        ptrContact tmp = head;
        head = head->next;
        tmp->next = NULL;
        free(tmp);
    }
}

ptrContact swap(ptrContact ptr1, ptrContact ptr2)
{
    ptrContact tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;

    return ptr2;
}

void sortData(int sortedBy, bool ascending)
{
    ptrContact *h;
    int i, j, swapped;

    for (i = 0; i <= countContact; i++)
    {
        h = &head;
        swapped = 0;
        for (j = 0; j < countContact - i - 1; j++)
        {
            ptrContact p1 = *h;
            ptrContact p2 = p1->next;

            switch (sortedBy)
            {
            case 1:
                if ((strcmp(p1->no_telp, p2->no_telp) > 0 && ascending) || (strcmp(p1->no_telp, p2->no_telp) < 0 && !ascending))
                {
                    *h = swap(p1, p2);
                    swapped = 1;
                }
                break;
            case 2:
                if ((strcmp(p1->name, p2->name) > 0 && ascending) || (strcmp(p1->name, p2->name) > 0 && !ascending))
                {
                    *h = swap(p1, p2);
                    swapped = 1;
                }
                break;
            case 3:
                if ((calculateAge(p1) > calculateAge(p2) && ascending) || (calculateAge(p1) < calculateAge(p2) && !ascending))
                {
                    *h = swap(p1, p2);
                    swapped = 1;
                }
                break;
            case 4:
                if ((p1->sex > p2->sex && ascending) || (p1->sex < p2->sex && !ascending))
                {
                    *h = swap(p1, p2);
                    swapped = 1;
                }
                break;
            case 5:
                if ((strcmp(p1->email, p2->email) > 0 && ascending) || (strcmp(p1->email, p2->email) < 0 && !ascending))
                {
                    *h = swap(p1, p2);
                    swapped = 1;
                }
                break;

            default:
                break;
            }
            h = &(*h)->next;
        }
        if (swapped == 0)
            break;
    }
}

void printData()
{
    printf("\n=================================================\n"
           "|\t\tMENU DAFTAR KONTAK\t\t|\n");
    ptrContact tmp = head;
    tmp = head;
    if (tmp == NULL)
    {
        printf("=================================================\n");
        printf("  Data masih kosong...\n");
        getch();
        return;
    }

    unsigned int pilihan, ascending, totalAge = 0, i;

    for (i = 1; tmp != NULL; i++)
    {
        printf("-------------------------------------------------\n");
        printSinglyContact(tmp, i);
        totalAge += calculateAge(tmp);
        tmp = tmp->next;
    }
    printf("=================================================\n");
    printf("  Rata-rata umur kontak: %0.2f tahun\n\n", (float)totalAge / (i - 1));
    printf("  Urutkan berdasarkan: \n");
    printf("  [1] No. Telp\n"
           "  [2] Nama\n"
           "  [3] Umur\n"
           "  [4] JK\n"
           "  [5] Email\n"
           "  [0] Kembali\n");
    printf("  >> Masukkan pilihan: ");
    scanf("%d", &pilihan);

    if (pilihan >= 1 && pilihan <= 5)
    {
        printf("\n  Pilihan urutan: \n");
        printf("  [1] Ascending\n"
               "  [2] Descending\n");
        printf("  >> Masukkan pilihan: ");
        scanf("%d", &ascending);
        switch (ascending)
        {
        case 0:
            return;
            break;
        case 1:
            sortData(pilihan, true);
            break;
        case 2:
            sortData(pilihan, false);
            break;
        default:
            break;
        }
    }
    else if (pilihan == 0)
        return;

    system("cls");
    printData();
}

int saveData()
{
    printf("\n=================================================\n"
           "|\t\tMENU SIMPAN KONTAK\t\t|\n"
           "-------------------------------------------------\n");
    char *filename = "bukuKontak.txt";

    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf(">> Tidak dapat menyimpan. %s\n", filename);
        return -1;
    }

    fprintf(fp, "name;dob;sex;no_telp;email;\n");
    ptrContact tmp = head;
    while (tmp != NULL)
    {
        fprintf(fp, "%s;%d-%d-%d;%c;%s;%s;\n", tmp->name, tmp->dob.year, tmp->dob.month, tmp->dob.day, tmp->sex, tmp->no_telp, tmp->email);
        tmp = tmp->next;
    }
    fclose(fp);
    printf(">> Data berhasil disimpan.\n");

    return 0;
}

int loadData()
{
    printf("\n=================================================\n"
           "|\t\tMENU LOAD KONTAK\t\t|\n"
           "-------------------------------------------------\n");
    char *filename = "bukuKontak.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf(">> File tidak ditemukan. Upload gagal.\n");
        return 1;
    }

    const unsigned MAX_LENGTH = 256;
    char data[MAX_LENGTH];

    fgets(data, MAX_LENGTH, fp);
    while (fgets(data, MAX_LENGTH, fp))
    {
        ptrContact newData;
        newData = (ptrContact)malloc(sizeof(struct contact));
        char *p = strtok(data, ";-");
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
                strcpy(newData->name, p);
                break;
            case 1:
                newData->dob.year = atoi(p);
                p = strtok(NULL, ";-");
                newData->dob.month = atoi(p);
                p = strtok(NULL, ";-");
                newData->dob.day = atoi(p);
                break;
            case 2:
                newData->sex = p[0];
                break;
            case 3:
                strcpy(newData->no_telp, p);
                break;
            case 4:
                strcpy(newData->email, p);
                break;
            }
            p = strtok(NULL, ";-");
        }
        newData->next = NULL;
        _id++;
        newData->_id = _id;
        insert(newData);
    }

    fclose(fp);
    printf(">> Data Berhasil Diupload\n");

    return 0;
}

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue *q)
{
    return q->front == -1;
}

bool isQueueFull(Queue *q)
{
    return (q->rear + 1) % 100 == q->front;
}

void enqueue(Queue *q, int value)
{
    if (isQueueFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    if (isQueueEmpty(q))
    {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % 100;
    q->data[q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % 100;
    }
    return value;
}

void add_edge(int src, int dest)
{
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}

bool BFS(int src, int dest, int pred[], int dist[])
{
    bool visited[100];
    for (int i = 0; i < _id; i++)
    {
        visited[i] = false;
        dist[i] = __INT_MAX__;
        pred[i] = -1;
    }
    visited[src] = true;
    dist[src] = 0;
    Queue q;
    initQueue(&q);
    enqueue(&q, src);
    while (!isQueueEmpty(&q))
    {
        int u = dequeue(&q);
        for (int i = 0; i < _id; i++)
        {
            if (adj[u][i] == 1 && !visited[i])
            {
                visited[i] = true;
                dist[i] = dist[u] + 1;
                pred[i] = u;
                enqueue(&q, i);
                if (i == dest)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void printShortestDistance(int source, int dest)
{
    int pred[100], dist[100];
    if (!BFS(source, dest, pred, dist))
    {
        printf(">> Kontak tidak terhubung satu sama lain.\n");
        return;
    }

    int path[100];
    int crawl = dest;
    int count = 0;
    path[count++] = crawl;
    while (pred[crawl] != -1)
    {
        path[count++] = pred[crawl];
        crawl = pred[crawl];
    }

    if (dist[dest] == 1)
    {
        printf(">> Kontak terhubung langsung.\n");
        return;
    }

    printf(">> Kontak tidak terhubung langsung, silahkan menghubungi: \n");

    for (int i = count - 2; i >= 0; i--)
    {
        ptrContact result = searhchById(path[i]);
        printf("%s (%s)\n", result->name, result->no_telp);
    }
}

int addKonektivitas(char *source, char *dest)
{
}

void konektivitasData()
{
    printf("\n=================================================\n"
           "|\t\tMENU BUAT KONEKTIVITAS\t\t|\n"
           "-------------------------------------------------\n");
    char source[15], dest[15];
    int _source_id, _dest_id;
    do
    {
        printf(">> Masukkan No. Telp Sumber: ");
        scanf(" %[^\n]s", source);
        ptrContact result = searchByTelp(source);
        if (result != NULL)
        {
            _source_id = result->_id;
            break;
        }
    } while (1);

    do
    {
        printf(">> Masukkan No. Telp Tujuan: ");
        scanf(" %[^\n]s", dest);
        ptrContact result = searchByTelp(dest);
        if (result != NULL)
        {
            _dest_id = result->_id;
            break;
        }
    } while (1);

    add_edge(_source_id, _dest_id);
    printf(" Sukses membuat konektivitas antara 2 kontak.\n");
}

void cekKonektivitas()
{
    printf("\n=================================================\n"
           "|\t\tMENU CEK KONEKTIVITAS\t\t|\n"
           "-------------------------------------------------\n");
    char source[15], dest[15];
    int _source_id, _dest_id;
    do
    {
        printf(">> Masukkan No. Telp Sumber: ");
        scanf(" %[^\n]s", source);
        ptrContact result = searchByTelp(source);
        if (result != NULL)
        {
            _source_id = result->_id;
            break;
        }
    } while (1);

    do
    {
        printf(">> Masukkan No. Telp Tujuan: ");
        scanf(" %[^\n]s", dest);
        ptrContact result = searchByTelp(dest);
        if (result != NULL)
        {
            _dest_id = result->_id;
            break;
        }
    } while (1);

    printShortestDistance(_source_id, _dest_id);
}

int main()
{
    unsigned int pilihan;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    presentDate.year = tm.tm_year = tm.tm_year + 1900;
    presentDate.month = tm.tm_mon + 1;
    presentDate.day = tm.tm_mday;

    do
    {
        system("cls");
        printf("\n=================================================\n"
               "|\tSELAMAT DATANG DI APLIKASI BUKU KONTAK\t|\n"
               "-------------------------------------------------\n"
               "| Silahkan Pilih Menu di Bawah Ini : \t\t|\n"
               "| [1]. Lihat Daftar Kontak \t\t\t|\n"
               "| [2]. Tambah Kontak\t\t\t\t|\n"
               "| [3]. Hapus Kontak\t\t\t\t|\n"
               "| [4]. Edit Kontak\t\t\t\t|\n"
               "| [5]. Cari Kontak\t\t\t\t|\n"
               "| [6]. Save Kontak\t\t\t\t|\n"
               "| [7]. Load Kontak\t\t\t\t|\n"
               "| [8]. Buat Konektifitas\t\t\t|\n"
               "| [9]. Cek Konektifitas\t\t\t\t|\n"
               "| [0]. Keluar\t\t\t\t\t|\n"
               "=================================================\n");
        printf(">> Masukkan Menu : ");
        scanf("%d", &pilihan);
        printf("\n");

        system("cls");
        switch (pilihan)
        {
        case 1:
            printData();
            break;

        case 2:
            createData();
            break;

        case 3:
            deleteData();
            getch();
            break;

        case 4:
            editData();
            getch();
            break;

        case 5:
            searchData();
            getch();
            break;

        case 6:
            saveData();
            getch();
            break;

        case 7:
            loadData();
            getch();
            break;

        case 8:
            konektivitasData();
            getch();
            break;

        case 9:
            cekKonektivitas();
            getch();
            break;

        default:
            return 0;
            break;
        }

    } while (pilihan != 0);

    return 0;
}
