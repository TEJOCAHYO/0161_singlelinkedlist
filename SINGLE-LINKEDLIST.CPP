#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};

class SingleLinkedlist
{
    Node *START;

public:
    List()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\n Masukkan Nomor Mahasiswa : ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs))
        {
            if (nim == current ->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }
    
    bool listEmpty()
    {
        return(START == NULL);

    }
    bool Search(int nim, node **previous, node **current)
    {
        *previous = START;
        *current = START;
        
        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }
        return (*current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!Search(nim, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;

    }
    void travense()
    {
        if (listEmpty())
        {
            cout << "\nList kosong\n";
        }
        else 
        {
            cout << "\nData didalam list adalah;\n";
            Node *currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;

            }
            cout << endl;
        }
    }
};

int main()
{  
    SingleLinkedlist mhs;
    int nim;
    char ch;
    while (1)
    {
        cout << endl
             << "menu";
        cout << endl
             << "1. menambah data kedalam list" << endl;
        cout << "2. menghapus data dari dalam list" << endl;
        cout << "3. menampilkan semua data didalam list" << endl;
        cout << "4. mencari data dalam list" << endl;
        cout << "5. keluar" << endl;
        cout << endl
             << "Masukan pilihan (1-5): ";
        cin >> ch;
        switch (ch)
        {
            case '1';
            {
                mhs.addNode();

            }
            break;

            case '2';
            {
                if (mhs.listEmpty())
                {
                    cout << endl
                         << "List kosong" << endl;
                    break;     
                }
                cout << endl
                     << "\nmasukan no mahasiswa yang akan dihapus : ";
                cin >> nim;
                if (mhs.delNode(nim) == false)
                    cout << endl
                         << "data tidak ditemukan" endl;
                else
                    cout << endl
                         << "data dengan nomor mahasiswa" << nim << "berhasil dihapus" << endl;

            }
            break;
            case '3':
            {
                mhs.travense();
            }
            break;
            case '4':
            {
                if (mhs.listEmpty() == true)
                {
                    cout << "\nlist kosong\n";
                    break;

                }
                node *previous, *current;
                cout << endl
                     << "masukan nomor mahasiswa yang di cari : ";
                cin >> nim;
                if (mhs.Search(nim, &previous, &current ) == false)
                    cout << endll
                         << "data tidak ditemukan" << endl
                else
                {
                    cout << endl
                         << "data tidak ditemukan" << endl;
                    cout << "\nNo mahasiswa: " << current-> noMhs << endl;
                    cout << "\n"
                }
            }
            break;
            case '5' :
            {
                exit(0);
            }
            break;
            default;
            {
                cout << "pilihan salah !. " << endl;
            }
            break;
        }
    }
}