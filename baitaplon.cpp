// Danh sach lien ket don
#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>

class Singlilist {
	public:
        Singlilist() {
            head = NULL;
            size = 0;
	    }

        ~Singlilist() {
			while (!empty()) {
				popFront();
			}
	    }

        // Kiem tra xem danh sach co rong hay khong.
        bool empty() {
			return(head == NULL);
	    }

        // Tra ve kich thuoc (so phan tu).
        int getSize() {
            return size;
        }

        // Tra ve phan tu dau danh sach.
        T front() {
            return head->elem;
        }

        // In cac phan tu tren cung mot dong, cach nhau boi dau cach.
        void print() {
            Node *p = head;
            while (p != NULL) {
                cout << p->elem << "  ";
                p = p->Next;
            }
            cout<<endl;
        }

        // Chen x vao dau danh sach.
        void pushFront(T x) {
            Node *v = new Node(x, head);
            head = v;
            size++;
            cout << "Da chen phan tu [" << x << "] vao danh sach" << endl;
        }

        int getFirstElem() {
            Node *p = head;
            return p->elem;
        }

        // Xoa phan tu dau danh sach.
        void popFront() {
            Node *old = head;
            head = head->Next;
            delete old;
            size--;
        }

        // Kiem tra xem danh sach co chua x hay khong.
        bool contains(T x) {
            Node *p = head;
            while (p != NULL) {
                if (p->elem == x) 
                    return true;
                p = p->Next;
            }
        }

        // Xoa x khoi danh sach (neu co).
        // Neu x xuat hien nhieu lan trong danh sach, chi xoa phan tu dau tien bang x.
        void remove(T x) {
            Node *p1 = NULL;
            Node *p2 = head;
            while (p2 != NULL) {
                if (p2->elem == x) {//tim thay x, can xoa x
                    if (p1 == NULL) {
                        head = head->Next;
                        delete p2;
                    }
                    else {
                        p1->Next = p2->Next;
                        delete p2;
                    }
                size--;
                cout << "Da xoa phan tu [" << x << "] khoi danh sach" << endl;
                break;
                }
                p1 = p2;
                p2 = p2->Next;
            }
        }
    private:
        // kieu du lieu cua cac nut trong danh sach
        struct Node {
            T elem;
            Node *Next;
            Node(T e, Node *n){
                elem = e;
                Next = n;
                }
        };

        Node *head;
        int size;
}; //end class

/* Yêu cầu
• Chèn một phần tử vào đầu danh sách
• Xóa một phần tử có nội dung cho trước khỏi danh sách
• Trả về kích thước danh sách
• Trả về nội dung phần tử đầu danh sách mà không hủy phần tử này
• Kiểm tra xem danh sách có rỗng hay khong
• Kiểm tra xem một phần tử cho trước có trong danh sách hay không
*/

int main() {
    //Khai báo danh sách
    Singlilist <int> list;
    char choose;
    int x, y;

    cout << "Ban co muon tao danh sach ban dau voi gia tri ngau nhien (C/K): " << endl;
    cin >> choose;
    while (true) {
        if (choose == 'c' || choose == 'C') {
            // Tao danh sach ban dau voi gia tri ngau nhien
            for (int i = 0; i < 10; i++) {
                int number = 1 + rand() % 110;
            list.pushFront(number);
            }
            break;
        }
        if (choose == 'k' || choose == 'K') {
            choose = 'c';
            //Tạo danh sách ban đầu bằng cách liên tục đẩy từng phần tử vào đầu danh sách
            while (true) {
                if (choose == 'c' || choose == 'C') {
                    cout << "Nhap phan tu muon chen: ";
                    cin >> x;
                    list.pushFront(x);
                }
                if (choose == 'k' || choose == 'K') {
                    break;
                }
                cout<<"Tiep tuc chen (C/K): ";
                cin >> choose;
                if (choose == 'c' || choose == 'C' || choose == 'k' || choose == 'K')
                    continue;
                else
                    cout << "Lua chon khong chinh xac!";
                
                cout << endl;
            }
            break;
        }
        cout << "Lua chon khong chinh xac!" << endl;
        cout << "Ban co muon tao danh sach ban dau voi gia tri ngau nhien (C/K): " << endl;
        cin >> choose;
    }
    
    //In ra nội dung danh sách và kích thước
    cout << "\nDanh sach vua tao (Kich thuoc = " << list.getSize() << "):" << endl;
    list.print();

    do {
        cout << "\n**********BANG CHON********** " << endl;
        cout << "1. Chen mot phan tu vao dau danh sach" << endl;
        cout << "2. Xoa phan tu [x] khoi danh sach" << endl;
        cout << "3. Lay kich thuoc danh sach" << endl;
        cout << "4. Lay phan tu danh danh sach ma khong huy phan tu nay" << endl;
        cout << "5. In toan bo danh sach" << endl;
        cout << "6. Kiem tra danh sach co rong hay khong" << endl;
        cout << "7. Kiem tra phan tu [x] co ton tai trong danh sach hay khong" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << endl;
        cout << "Nhap lua chon cua ban (0 -> 7): ";
        cin >> y;
        switch (y) {
            case 1: {
                cout << "Nhap phan tu muon chen: ";
                cin >> y;
                list.pushFront(y);
                cout << "\nDanh sach hien tai (Kich thuoc = " << list.getSize() << "):" << endl;
                list.print();
                break;
            }

            case 2: {
                cout << "Nhap phan tu muon xoa: ";
                cin >> y;
                if (!list.contains(y))
                    cout << "Phan tu [" << y << "] khong ton tai trong danh sach!" << endl;
                else {
                    list.remove(y);
                    cout << "\nDanh sach hien tai (Kich thuoc = " << list.getSize() << "):" << endl;
                    list.print();
                }
                break;
            }

            case 3: {
                cout << "Kich thuoc hien tai la: " << list.getSize() << endl;
                break;
            }

            case 4: {
                cout << "Phan tu dau tien la: " << list.getFirstElem() << endl;
                break;
            }

            case 5: {
                cout << "\nDanh sach hien tai (Kich thuoc = " << list.getSize() << "):" << endl;
                list.print();
                break;
            }

            case 6: {
                if (list.empty())
                    cout << "Danh sach rong!" << endl;
                else
                    cout << "Danh sach khong rong" << endl;
                break;
            }

            case 7: {
                cout << "Nhap phan tu muon kiem tra: ";
                cin >> y;
                if (!list.contains(y))
                    cout << "Phan tu [" << y << "] khong ton tai trong danh sach!" << endl;
                else {
                    cout << "Phan tu [" << y << "] ton tai trong danh sach" << endl;
                }
                break;
            }

            case 0: {
                cout << "Lua chon thoat!" << endl;
                y = 0;
                break;
            }

            default: {
                cout << "Lua chon khong hop le!" << endl;
                break;
            }
        }
    } 
    while(y!=0);

    // system("pause");
    return 0;
}
