#include <iostream>

using namespace std ;


/************ Function To Display Menu **********/
void Menu() {
    cout << "\n********** Menu **********\n" ;
    cout << "1. Insert\n" ;
    cout << "2. Search\n" ;
    cout << "3. Delete\n" ;
    cout << "4. Display\n";
    cout << "5. Exit\n\n" ;
}

/************* Hash Generator Function ***********/
// Note : This Function Must Be As Much Efficient As Possible
int hashFunction(int value) {
    return (value % 10) ;
}

/*************** Insert() Function ***************/
// Note : Max. 10 elements can be inserted, because i take the size of hash table
// to be 10 (Obviously, you can increase the table size)
void Insert(int * arr, int value) {
    
    int hash = hashFunction(value) , h = 0 ;
    int initialHash = hash;
    
    while (arr[hash] != 0 && h <= 10) {
        ++h;
        hash = (initialHash + h) % 10;
    }
    
    if (h > 10 ) {
        cout << "\nTable is full, Operation Aborted ... \n";
        return;
    }
    
    arr[hash] = value ;
}

/*************** Search Function *******************/
void Search(int * arr, int value) {
    
    int hash = hashFunction(value) , h = 0;
    int initialHash = hash;
    
    while (arr[hash] != value && h <= 10) {
        ++h;
        hash = (initialHash + h) % 10;
    
        if (arr[hash] == 0)
            break;
    }
    
    if (arr[hash] == value)
        cout << "\nFound\n" ;
    else
        cout << "\nNot Found\n" ;
    
}

int searchToDelete (int * arr,int value) {
    
    int hash = hashFunction(value) , h = 0;
    int initialHash = hash ;
    
    while (arr[hash] != value && h <= 10) {
        ++h;
        hash = (initialHash + h) % 10 ;
        
        if (arr[hash] == 0)
            break;
    }
    
    if (arr[hash] == 0 || arr[hash] != value)
        return 0;

    return hash;
}

void Delete(int * arr, int value) {
    
    int hash = searchToDelete(arr, value);
    
    if(hash == 0) {
        cout << "\nvalue Not Found, Operation Aborted\n";
        return;
    }
    
    arr[hash] = -1 ;
}

void Display(int * arr) {
    
    for (int i = 0; i <= 9; ++i)
        cout << arr[i] << " " ;
    
}


/*********** Main Function ************/
int main () {
    
    int arr[10] = { 0 } , ch , value ;
    
    Menu();
    cout << "Enter Your Choice : " ;
    cin >> ch ;
    
    while (ch >= 1 && ch <= 4) {
        
        if (ch == 1) {
            cout << "Enter Value To Insert : " ;
            cin >> value;
            Insert(arr, value);
        }
        
        else if (ch == 2) {
            cout << "Enter Item To Search : " ;
            cin >> value ;
            Search(arr, value);
        }
        
        else if (ch == 3) {
            cout << "Enter item to delete : " ;
            cin >> value ;
            Delete(arr, value);
        }
        
        else
            Display(arr);
        
        cout << "\n" ;
        
        Menu();
        cout << "Enter Your Choice : " ;
        cin >> ch ;
    }
    
    
    return 0 ;
}
