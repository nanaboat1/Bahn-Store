#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <string.h>

using namespace std; //using standard namespace. 

//Function Prototypes
char shelfname_stringtoChar_Row(string shelfIndex);
char shelfname_stringtoChar_Column(string shelfIndex);
int numerical_Value_ofRowindex(char shelfname_stringtoChar_Row);
int numerical_Value_ofColumnindex(char shelfname_stringtoChar_Column);
bool authorizing_user();
int random_generator();
string check_employee();
double cash_rewards(double total_price);
int buy_itemFromshelf();
static void business_analytics( int state, double session);




class  Customer{
public:


  bool authorization; // gives authorization to the customer to buy things from the store 
  double receipt_bill; //stores the total purchase of the customer
  int cash_rewards; //a promotional something, I have not figured it out so do not ask me what it does. 
  int customer_ratings;
  int key;//stores authorizing key to validate the user. 
  string shelf_select;


  //Constructor 
  Customer(){


    authorization = false;
    receipt_bill = 0.00;
    cash_rewards = 0.00;
    customer_ratings = 0; 
    key = 1235; 
    shelf_select = "aA";  
    
  }
  
    //Methods for this class
    bool authorizing(){

      authorization = authorizing_user();//Calls authorizing_user  and validates the user
      return authorization ;
    }

  int ratings(){ 

    
    cout << " How was your experience today shopping with us. Please rate us from 1 to 5 :)  -->  ";
    cin >> customer_ratings;    
    return customer_ratings;
    
    
  }

  int cashRewards(){
    //Depending on certain conditions then a number is given to cash rewards which is evaluated 
    //based on certain criterias. Which will be filled in later.
    return cash_rewards; 
  }

  double addToBill(int price){

    if(authorization){  
      receipt_bill += price;
      return receipt_bill; 
    }
    else{
      return receipt_bill; 
    } 
  }

  string selectShelf(){

    cout <<"------------------------"<<endl;
    cout << "Enter the shelf index ";
    cin>>shelf_select;    
    cout <<"------------------------"<<endl;

    return shelf_select; 
  }

};
class Stocker{
public:
    bool authorisation; 
    string shelf_select;
    bool assistance;//
    int key;//stores authorizing key to validate the user. 

    Stocker(){
      authorisation = false;
      shelf_select = "aA";//Default shelf value
      assistance = false;
      key = 1234;//default value for the key.
    }

    bool authorising(){

      authorisation = authorizing_user();//Calls authorizing_user to validate the user.
      return authorisation = true;     
    }

    string selectShelf(){

      cout <<"--------------------------"<<endl;
      cout <<  "Enter the shelf code ";
      cin >> shelf_select;    
      cout <<"--------------------------"<<endl;
      return shelf_select; 
    }
};
class BusinessAnalytics{//more to add to the code will do that in the coming days 
public:
    bool autharise; 
    double totalSales;
    int totalItemspurchased;
    /*  data fields to store the total items purchased. */  
    

    //creating a constructor for the class
    BusinessAnalytics(){
      autharise = true;
      totalSales = 0.00;
      totalItemspurchased = 0;
      
    }

    //Methods for this class
    bool authorizing(){

      autharise = authorizing_user();//Calls  authorizing_user to validate the user.
      return autharise;
    }

    int total_itemspurchased_session(int items_per_Session){
      
      totalSales +=items_per_Session;
      return totalItemspurchased;

    }

    
  /*For the Profits Method, I have to be really critical of this. I will do this after I have found how the code is going to work. */
};
void shelf_display(double unitPrice[5], string warehouseItems[5], int warehouseStks[5]){



  //Using loops to print the shelf to the User. 
    cout << "---------------------------------------------------"<<endl;
    cout << "SHELF-INDEX| ITEM NAME     | QUANTITY | UNIT PRICE|"<<endl;
    cout << "---------------------------------------------------"<<endl;
  for(int i = 0; i < 5;i++){
    cout <<"| A"<<i + 1<< "       |"<< warehouseItems[i] <<"     |      "<<warehouseStks[i]<<"   |      "<<unitPrice[i]<<"|"<<endl;
  }
    cout << "---------------------------------------------------"<<endl;
  //Shelf block. 


}
void receipt_printer(double total_price){

  cout << "------------------------------------------------"<<endl;
  cout << "          [] BAHNHOFSTRASSE ®                   "<<endl;
  cout <<endl;
  cout << "                       SUBTOTAL: "<< total_price<<endl;
  cout << "                            TAX: "<< "8.9 % "<<endl;
  total_price = (1.089)*static_cast<int>(total_price);
  cout << "                          TOTAL: "<< total_price<<endl;
  cout << "---##                                      ##--    "<<endl;
  cout<<endl;
  cout << "        THANKS, [] BAHNHOFSTRASSE ® MErrrY XmaS."<<endl;
  cout<<  "------------------------------------------------"<<endl;
  cout << "------------------------------------------------"<<endl;
  cout << "|<--        Bahnhostrasse® Department Store -->|"<<endl;
  cout << "------------------------------------------------"<<endl;


}
void localizer(int quantity_Arry[]){

  /*This function localizes all the arrays to enhance printing during complile time */
  //Because the arrays of Unit_price and Item list are standard and they do not change, they will
  // be coded brute forcely, Also I am new to this and dont want errors beyond my scope, thats why they are hard
  //coded. The only array that will not be hard coded is the quantity array because it changes during runtime.


  const int item_type = 5;
  double prize_shelf[item_type];
  prize_shelf[0] = 17.99;
  prize_shelf[1] = 35.99;
  prize_shelf[2] = 99.99;
  prize_shelf[3] = 12.99;
  prize_shelf[4] = 13.99;
   

  string warehouse_items[item_type];
  warehouse_items[0] = "Cloth's-Cl";
  warehouse_items[1] = "Watch-Delu";
  warehouse_items[2] = "Smartphnes";
  warehouse_items[3] = "Book-fictn";
  warehouse_items[4] = "Fast-foods";


  shelf_display(prize_shelf ,warehouse_items,quantity_Arry );
    
}
//The below functions are used to access the arrays.
int call_buyitem( bool buy ){

  if(buy){

    return buy_itemFromshelf();
  }
  else{

    return 0;
  }
}
int buy_itemFromshelf(){

  /*This function asks the user the quanity of item the user wants to remove from the shelf.
  */ 

  int _quant = 0;

  //takes in the users quantity 

  cout << "  How many quantities are you buying-->  ";
  cin >> _quant;   

  return _quant;
}
int quantity_add(){

  /* This function is used to add extra quantity to the shelf , when requested by the stocker or cashier */

  int add_quant = 0;

  cout << "Enter the quanity amount you want to add--> ";

  cin >> add_quant;

  return add_quant;
}
// This list of function manipulators helps access the shelf array based on the users input.

char chartoNum(char ch){

  if( static_cast<int>(ch)>=48&&static_cast<int>(ch)<58){//returns the numbers if user input are numbers
    return ch;//returns the ch when the input is a number.
  }

  else if(static_cast<int>(ch)>96&&static_cast<int>(ch)<123){//when the input is lower case, we need to convert it to upper case.

    return toupper(ch);//converts it to its upper case character then tranlates it to a phone number. 
  }

  else if(static_cast<int>(ch)>=65&&static_cast<int>(ch)<=90){//when the letter is already in upper case.
    return ch; //When the number is already in upper case it calls dialchartonum to give its corresponding phone number.
  }

  return ch = '_';//when an unlikely error occurs
}
string correctshelfName(string shelfindex){

  //The correctshelfName function corrects the users input of the shelf number to the standard format required by the program
  //to prevent runtime issues.  

  string standardShelfname = "aa";//stores tesf. //the value inside is an arbitrarily value to prevent error during compile time.   
  for(int i = 0; i <2; i++){  

   standardShelfname[i] = chartoNum(shelfindex[i]);
  }

  return standardShelfname;

  //The customer class will use the return value when the customer class  is objectisied.
}
int specific_ASCIIofChar_shelfIndex(int totalASCII_of_index){



  /* This function uses the total ASCII value of the shelf index and switch statement to return its
  corresponding value to the array. 
  */

  switch(totalASCII_of_index){

    case 114://when the Array shelf is A1.( Total ASCII value ==> 114)(A1, is the first column.)

      return 0;//it returns 0  
    break;

    case 115://when the Array shelf is A2. (Total ASCII value ==> 115)(A2, is the second column.)

      return 1;
    break;
    case 116://when the Array shelf is A3. (Total ASCII value ==> 116)(A3, is the third column.)

      return 2;
    case 117://when the Array shelf is A4. (Total ASCII value ==> 117)(A4, is the fourth column.)

      return 3;
    break;
    case 118://when the array shelf is A5. (Total ASCII value ==> 118)(A5, is the fifth column. )

      return 4;
    break;
  }
  return 8;//returns this to prevent an error from happening
}
//This lists of functions, consists of the shelfs of the store
double unitprice(string warehouseIndex){

  /* This function contains the arrays that stores the unit prices of the individual items in the shelf. */

  //correctshelfName(), evaluates the user input to the standard shelf index to prevent errors and let the code run perfectly.

  warehouseIndex = correctshelfName(warehouseIndex);
  const int item_type = 5;
  double unit_price = 0;
 
  double prize_shelf[item_type];
  prize_shelf[0] = 17.99;
  prize_shelf[1] = 35.99;
  prize_shelf[2] = 499.99;
  prize_shelf[3] = 12.99;
  prize_shelf[4] = 13.99;

  //The block of code evaluates the users input into array index which can be used to assess an array value.
  /* The numerical values of the row and column index are gotten and then assiged to int varibles*/
  int numerical_val_row = numerical_Value_ofRowindex(shelfname_stringtoChar_Row(warehouseIndex)); //The numerical value of Row index is gotten is evaluated by calling the functions. 
  int numerical_val_column = numerical_Value_ofColumnindex(shelfname_stringtoChar_Column(warehouseIndex));//The numerical value of column index is evaluated by calling the functions.
  /* After I have gotten the numerical values, I send it to a function that uses switch statements to evaluate them and couts a unique
  value that can be used by the warehouse to give a specific index of the shelf
  */
  int total_numerical_valRow_Clmn = numerical_val_row + numerical_val_column;//this variables stores the total numerical value of row index and column index. 
  //cout << total_numerical_valRow_Clmn << endl; used for testing purposes
  int index_to_be_accessed = specific_ASCIIofChar_shelfIndex(total_numerical_valRow_Clmn);
  //cout << index_to_be_accessed << endl;used for testing purposes.



  for(int i = 0; i <= index_to_be_accessed; i++){
    unit_price = prize_shelf[i];
  }

  return unit_price;
}
string warehouseItems(string warehouseIndex, bool state ){  

  const int item_type = 5;//size of array. 

  //correctshelfName(), evaluates the user input to the standard that prevents compile issues.
  warehouseIndex = correctshelfName(warehouseIndex);

 /*For compile reasons, this array is hard coded with predefined stuffs and time convenience */
   string warehouse_items[item_type];
    warehouse_items[0] = "Cloths";
    warehouse_items[1] = "Watch";
    warehouse_items[2] = "Smartphones";
    warehouse_items[3] = "Books";
    warehouse_items[4] = "Fast food";

  


  //The block of code evaluates the users input into array index which can be used to assess an array value.
  /* The numerical values of the row and column index are gotten and then assiged to int varibles*/


  int numerical_val_row = numerical_Value_ofRowindex(shelfname_stringtoChar_Row(warehouseIndex)); //The numerical value of Row index is gotten is evaluated by calling the functions. 
  int numerical_val_column = numerical_Value_ofColumnindex(shelfname_stringtoChar_Column(warehouseIndex));//The numerical value of column index is evaluated by calling the functions.
  /* After I have gotten the numerical values, I send it to a function that uses switch statements to evaluate them and couts a unique
  value that can be used by the warehouse to give a specific index of the shelf
  */
  int total_numerical_valRow_Clmn = numerical_val_row + numerical_val_column;//this variables stores the total numerical value of row index and column index. 
  //cout << total_numerical_valRow_Clmn << endl; This line is used for testing purposes
  int index_to_be_accessed = specific_ASCIIofChar_shelfIndex(total_numerical_valRow_Clmn);
  //Then the total ASCII is send to the specificChar

  //cout << index_to_be_accessed << endl; This line is used for testing purposes.


  string item_to_disp;
  for(int i = 0; i <= index_to_be_accessed; i++){
    item_to_disp = warehouse_items[i];
  }
  return item_to_disp;
}
static int warehouseStock(string warehouseIndex, int state, int send_shelf, bool buy){//This contains the quantities of stock in the warehouse with the prize.

  const int item_type = 5;


  //correctshelfName(), evaluates the user input to the standard shelf index to prevent errors and let the code run perfectly +- 0.0001.
  warehouseIndex = correctshelfName(warehouseIndex);
 /*For compile reasons, this array is hard coded with predefined stuffs and also given the limited time we are supposed to this. */


  static int warehouse_items[item_type] = {4, 3, 2 ,2 ,3};//template array for stock.
  //The block of code evaluates the users input into array index which can be used to assess an array value.
  /* The numerical values of the row and column index are gotten and then assiged to int varibles*/


  int numerical_val_row = numerical_Value_ofRowindex(shelfname_stringtoChar_Row(warehouseIndex)); //The numerical value of Row index is gotten is evaluated by calling the functions. 
  int numerical_val_column = numerical_Value_ofColumnindex(shelfname_stringtoChar_Column(warehouseIndex));//The numerical value of column index is evaluated by calling the functions.
  /* After I have gotten the numerical values, I send it to a function that uses switch statements to evaluate them and couts a unique
  value that can be used by the warehouse to get the  specific index of the shelf*/


  int total_numerical_valRow_Clmn = numerical_val_row + numerical_val_column;//this variables stores the total numerical value of row index and column index. 
  //cout << total_numerical_valRow_Clmn << endl; This line of code is used for testing purposes
  int index_to_be_accessed = specific_ASCIIofChar_shelfIndex(total_numerical_valRow_Clmn);
  /*                                                                           */


  // Variable for the quantity  to take from the shelf array. 
  int take_quant_FromShelf = 0;
  int quantity_to_disp = 0;
  


  if(state == 0){
    //This block of code runs for only the Customer class, when the bool state is true.

    //Only used when he or she is buying something.
    
    //The quantity to take from the shelf is specified by calling the buy_itemFromshelf() function. 
    take_quant_FromShelf = call_buyitem(buy);

    cin.ignore();
    
    //This loops is used to iterate through the array to get the item the user is buying.
    //cout <<  warehouse_items[index_to_be_accessed]<<" ";

    for(int i = 0; i <=index_to_be_accessed; i++){  

      warehouse_items[i] =  warehouse_items[i] - take_quant_FromShelf;// updates the array by removing the quanity the user bought from the array. 
    }


    return  warehouse_items[index_to_be_accessed];  //take_quant_FromShelf;//returns the quantity of the item the user bought.
    
  }
  else if( state == 1){

    //This block of code runs  only for the Stocker class, when the bool state is false.
    //and it is done to check quantity in an array and add more and nothing else. 
    //cout << index_to_be_accessed << endl;This line of code is used for testing purposes. 
    
    int yes_or_no = 0;//The variable is used to store the users choice.

    do{
    //this variables displays the quantity of the specific shelf to the user.

    //The loop displays the specific warehouse shelf Item quanity asked for.
    for(int i = 0; i <=index_to_be_accessed; i++){

      quantity_to_disp = warehouse_items[i];

    }

    cout << "Quantity is " << quantity_to_disp << endl;
  
    /* This block of code will ask the Stocker is she wants to add extra quantity of the item to the specific shelf 
    If the user opts not to add more quantities to the shelf the shel wont increase but if she opts to then it will increase*/
    

    //More quantities is added to the index being accessed. 
      warehouse_items[index_to_be_accessed] += quantity_add();

      //Then the new quanity is displayed rather than the old one. 

      /* This loops then displays the quantity in that specific shelf after the user adds the quantity*/

      for(int i = 0; i <= index_to_be_accessed; i++){


        quantity_to_disp = warehouse_items[i];
      }

      cout << "New Quanity is--> " << quantity_to_disp << endl;

      cout << "Do you want to exit Yes --> (1) or No --> (0) "<<endl;

      cin  >> yes_or_no;

    }while( yes_or_no != 1);
          
     
  }
  else{


    //I devised a smart way to return all the array values to another function. It's crazy but it works!!

    return warehouse_items[send_shelf];
  }

  return quantity_to_disp;//return value for expression on ln 427.
}
//The following functions help convert the users input into int values to help access the shelf arrays.
int numerical_Value_ofRowindex(char convert_rowchar_toInt){
  /*This function converts the rowIndex char gotten from shelfname_stringtoChar_Row to its corresponding ASCII value (integer value)
  */
  
  return static_cast<int>(convert_rowchar_toInt);
}
int numerical_Value_ofColumnindex(char convert_columnchar_toInt){
  /*This function converts the column char gotten from shelfname_stringtoChar_Column to its corresponding ASCII value (integer value)
  */

  
  return convert_columnchar_toInt;
}
char shelfname_stringtoChar_Row(string shelfIndex){//The parameter is the shelf place the user wants to access.
    // This function breaks the user input(Shelfindex of row to be evaluated by the add new item category)
    

    char string_index_to_char_row; 

    //char column_index;

    for(int i = 0; i <1; i++){

     string_index_to_char_row = shelfIndex[i];

    }
    //For testing reasons, I included the cout.

    //cout << string_index_to_char_row << endl;

    return string_index_to_char_row;
}
char shelfname_stringtoChar_Column(string shelfIndex){//The parameter is the shelf place the user wants to access. 
  // This function breaks the userinput(Shelfindex of column to be evaluated by the add new item category)
 
  char string_index_to_char_column; 

  //char column_index;

  for(int i = 0; i <2; i++){


    string_index_to_char_column = shelfIndex[i];
  }
  //For testing reasons, I included the the cout below. 

  //cout << string_index_to_char_column << endl;

  return string_index_to_char_column;
}
void myStore_Backend(string employeeID){

 bool buy_no = false;

  int shelf_stock[5]; 

  for(int i = 0; i < 5; i++){



    shelf_stock[i] = warehouseStock("a1", 2, i, buy_no);

  }

  cout<<endl;

  localizer(shelf_stock);


  cout << "You can add more Quantity to the shelf " << endl;

  cout << endl;

    
  Stocker Cashier;// Instantiated the Stocker class
     
  //Calls the authorising function to validate the user. 

  Cashier.authorising();

  int state = 1;//used to alternate between different processes in warehouse stock. 

  /* The Cashier needs to know the warehouse items hence the array will be displayed to the user first */



  Cashier.shelf_select = Cashier.selectShelf();


  cout << warehouseItems(Cashier.shelf_select, state) << ":"<< endl <<warehouseStock(Cashier.shelf_select, state,0,buy_no);
    
  for(int i = 0; i < 5; i++){


    shelf_stock[i] = warehouseStock("a1", 2, i, buy_no);
  }

  cout<<endl;


  localizer(shelf_stock);

  cout << "----------------"<<endl;
  cout <<"|Session End... |"<<endl;
  cout << "----------------"<<endl;

  cout<<endl;

    
 
}
double myStore_Frontend(){

  int state = 0;//this state is used to access the the warehouse and call specific functions based on this state.
  Customer Client; 

  //Calls the authorizing user method of the class.
  Client.authorizing();
  cout << "Please, what do you want to buy Today []" << endl;
  //This block of code gets the values of quantity array from warehouseStock function. 
  //to be used here to print a shelf. 
  static int shelf_stock[5]; 
  for(int i = 0; i < 5; i++){
    shelf_stock[i] = warehouseStock("a1", 2, i, false);//template to get the array values from a warehouse Stock.
  }
  //
  cout<<endl;
  //localizer function gets called to display the shelf to the user.
  localizer(shelf_stock);

  int done =0;
  int yes_or_no = 0;
  int exit_loop = 0;
  /*This loop is used in the shopping process of the user.  */
  

  do{

    Client.shelf_select = Client.selectShelf();
    bool buy_no = false;
    cout << warehouseItems(Client.shelf_select ,state) << ": Quantity is  [" << warehouseStock(Client.shelf_select, state,0,false) << "]";
    //The customer's billing method gets called and the total price is the quantity the user chose multiplied by the unit price.
    // and all this is done by the indexvalue of the user. All  values for unit price, itemname and quanitity are correlated together by the same index name///
    bool buy_yes = true;
    Client.addToBill(unitprice(Client.shelf_select)*warehouseStock(Client.shelf_select,state,0, buy_yes)); 
    // Also, find ways you are going to store the users selection in an array so that u can print a receipt from it 
    //then when the thing is picked it gets updated in the array.    
    //print receipt, buy stuffs call. stocker. customer rating. Authorizing .
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout << " Hello Customer, are you done shopping (1)-->(Yes) || (0)-->(No) ";
    
    cin >> yes_or_no;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

    switch(yes_or_no){
      case 1:
        exit_loop++;
      break;
      case 0:
        exit_loop = 0;
      break; 
    }
   /* An array that stores the users bought item and then tracks that with the price and prints a receipt. */ 
   //Business Analytics is called to store the total sales per session.
    //gets the total items purchased in a session.

  }while(exit_loop != 1);

  Client.receipt_bill =  cash_rewards(Client.receipt_bill);//calls the cash rewards function if the user meets the criteria.

  cout<<endl;
  cout << "Your Receipt... "<<endl;
  cout <<endl;
  //Prints receipt to the User.
  receipt_printer(Client.receipt_bill);
  cout << endl;
  cout <<endl;
  Client.ratings();
  cout<<endl;
  cout << "----------------"<<endl;
  cout <<"|Session End... |"<<endl;
  cout << "----------------"<<endl;
  cout<<endl;

  return Client.receipt_bill;//The total bill of the user.//Could do something cool with this in business analytics. 
}
static void programStore(){
  int users_selection = 0;

  while(users_selection == 0){

    cout << "---------------------------------------------------------"<<endl;
    cout << "|<--Hello Welcome to Bahnhostrasse® Department Store -->|"<<endl;
    cout << "---------------------------------------------------------"<<endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------------"<<endl;
    cout <<" Hello!! select 1 if you are Customer. |"<<" Select 2 if you are an Employee | Select 3 if you are the Manager "<<endl;
    cout << "--------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout <<"Enter you selection --> ";

    cin >> users_selection;

    cout << endl;

  }

  static double send_to_manager;

  switch (users_selection)
  {
  case 1:

    cout << "Welcome to Bahnhofstrasse, Customer ®"<<endl;

    cout<<endl;

    send_to_manager = myStore_Frontend();

    business_analytics(1, send_to_manager);

  break; 
  case 2:

    cout << "Welcome to Banhofstrasse, Employee ®"<<endl;

    cout<<endl;

    myStore_Backend(check_employee());    
  break;
  case 3:

    business_analytics(2, 0);
  


  }

  
  
}
static void business_analytics( int state, double session){

  

  BusinessAnalytics Manager;
  Manager.authorizing();//authorizes the user
  
  static double total_sales = 0;

  if(state == 1){
    //stores the total price per session of the customer. 

    total_sales += session;

    Manager.totalSales += session;//Manager object gets the data. 
  }
  else{

    //when the business analytics class is called in the program store function.

    cout << " Manager, Current Total sales is -->  " << total_sales << "  Bahnhofstrasses [] " << endl;
    cout <<endl;
    cout << endl;
  }


}
int main(){

  int not_exit = 1;

  while( not_exit == 1){



    programStore();

  } 
  

  return 0;
}
bool authorizing_user(){

  cout << "Hello, User welcome to the Store. To be able to access the store, we need to verify you are not a robot "<<endl;//gives information to the user about this step. 
  int _validator;

  int users_check;

  cout << endl;
  
  cout <<"----------------------------------------"<<endl;
  do{ 
    
    _validator = random_generator();
    cout << "Enter this key ==>  " << _validator << " to get verified " << endl;
    cout << "Enter here --> ";
    cin >> users_check; 
    
    
  }while(users_check !=_validator);

  cout <<"-----------------------------------------"<<endl;
  cout <<"*****************************************"<<endl;


  return true; // returns true so that 
}
int random_generator(){
  /*This function generates a random number by calling the rand function and returns the int  */


  srand(time(NULL)); //seed the random library with the current time


  return rand() % 3452;// returns a generated random number. 
}
string check_employee(){

  string employee_Id;

  cout << "Welcome employee, Please  Enter you Employee ID ,below "<<endl;
  cout <<" -----------------"<<endl;
  cout <<" Enter ID -->   ";
  cin >> employee_Id;
  cout <<" -----------------"<<endl;
  cin.ignore();


  return employee_Id;
  
}

double cash_rewards(double total_price){

  //This function checks a user eligibility for cash rewards. 

  if(total_price > 50 && total_price < 100){
    cout << "Congratulations you won 2 percent Cash back rewards "<< endl;
    total_price = 0.98*total_price;
    return total_price;
  }
  else if(total_price > 100 && total_price < 1000){
    cout << "Congratulations you won 3 percent Cash back rewards "<<endl;
    total_price = 0.93*total_price;
    return total_price;
  }
  else if(total_price > 1000 && total_price < 10000){//cash rewards for this price range
    cout << "Congratulations you won 5 percent Cash back rewards "<<endl;
    total_price = 0.95*total_price;
    return total_price;
  } 
  else{
    return total_price;//if it does not meet any of the criteria then normal price is printed.
  }
}


/* The program is a simple simulation of a store . I implemented many maniuplations of arrays and
functions. I used ASCII values and function parameters states to give functions two micor functions and processes
that gets initiated depending on the state. Most of the comments are found in the code itself. and my Documentation
And also for compile reasons, I add to remove some of my features to prevent runtime errors I could not understand within my scope. . 

Nana Boateng Amoah- CS-171-4. 2019. */



