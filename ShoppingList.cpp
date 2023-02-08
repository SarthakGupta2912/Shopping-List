#include <iostream.h>
#include <conio.h>
using namespace std;

class ShoppingList
{
    public:
    int itemNum[10];
    int qty[5]= {0,0,0,0,0};
    int priceEachItem[5]={10,5,15,20};
    int itemCount=4, totalCost=0;
    char foodItem[5][100]={"Pizza ", "Paneer Tikka ", "Paneer naan with gravy ", "paneer burger "};

    public:
    void AddItem();
    void DeleteItem();
    void DisplayItemList();
    void Exit();
    void Menu();
};
void ShoppingList :: AddItem()
{
    int itemVal=0;
    cout<<"\nPress 1 to add Pizza for $10.\nPress 2 to add Paneer tikka for $5.\nPress 3 to add Paneer naan with gravy for $15.\nPress 4 to add paneer burger for $20.\nPress any other key to exit to the main menu.\n\nEnter a value: ";
    cin>>itemVal;

    if(itemVal <= itemCount && itemVal >0){
        totalCost+= priceEachItem[itemVal-1];
        qty[itemVal-1] += 1;
        cout<<"Item added successfully!\n";
    }
    else
        cout<<"Exiting...\n";
}
void ShoppingList :: DisplayItemList(){
    
    for (int i = 0; i < 4; i++)
    {
        cout << "\n\nS.No "<<i+1<< "\nItem name: "<< foodItem[i] << "\nPrice: $" << priceEachItem[i]<<"\nQuantity: "<<qty[i];
    }
    cout<< "\n\nYour total bill is: "<< totalCost<<endl;
    cout<< "Thanks for eating, see you soon! :-)\n";
}

void ShoppingList :: DeleteItem()
{
    int itemVal=0;
    cout<<"\nPress 1 to delete Pizza for $10.\nPress 2 to delete Paneer tikka for $5.\nPress 3 to delete Paneer naan with gravy for $15.\nPress 4 to delete paneer burger for $20.\nPress any other key to exit to the main menu.\n\nEnter a value: ";
    cin>>itemVal;

    if(itemVal <= itemCount && itemVal >0){

        if(qty[itemVal-1] == 0)
            cout<<"You have not purchased the respecrive item yet!\n";

        else{
        totalCost-= priceEachItem[itemVal-1];
        qty[itemVal-1] -= 1;
        cout<<"Item deleted successfully!\n";
        }
    }
    else
        cout<<"Exiting...\n";
}

void ShoppingList :: Menu()
{
    int num;    
    cout<<"\nPress 1 for adding items from the list given below.\nPress 2 for deleting the items from your list.\nPress 3 to display your item list.\nPress any other key to exit.\n\nEnter a value from the above menu: ";
    cin>>num;
   
    switch (num)
    {
    case 1:
        AddItem();
        Menu();
        break;
    case 2:
        DeleteItem();
        Menu();
        break;
    case 3:
        DisplayItemList();
        Menu();
        break;
    default:
        cout<<"Program terminated successfully!";
        exit(0);
        break;
    }
}
int main()
{
    ShoppingList sLObj;
    sLObj.Menu();
    return 0;
}