#include <iostream>

using namespace std;

class  Customer{
public:
    bool authorization; // gives authorization to the customer to buy things from the store 
    double receipt_bill; // stores the total purchase of the customer
    int cash_rewards; //a promotional something, I have not figured it out so do not ask me what it does. 
    int customer_ratings;

    //Constructor for this class. When the class is istantiated default values are given to the data fields during compile time. 
    Customer(){
        authorization = false;
        receipt_bill = 0.00;
        cash_rewards = 0.00;
        customer_ratings = 0;    
    }

    //Methods for this class
    bool authorizing(){//This method changes the value of authorization field to true.
        return authorization = true;
    }

    int ratings(){//this method asks the user to rate the experience in using the store. 

        if(authorization){// this method is enabled only when the user has been authorized.
        cout << " How was your experience today shopping with us. Please rate us from 1 to 5 :) "<<endl;
        cin >> customer_ratings;    
        return customer_ratings;
        }
        else{
            customer_ratings = 0;
            return customer_ratings;//returns the default constructors value for customers ratings
        }
    }
    int cashRewards(){
        //Depending on certain conditions then a number is given to cash rewards which is evaluated 
        //based on certain criterias. Which will be filled in later.
        return cash_rewards; 
    }
    double addToBill(int price){

        if(authorization){  
        receipt_bill += price;
        return receipt_bill;// adds the prize to the receipt bill then returns the new prize. 
        }
        else{
            return receipt_bill; // returns the original receipt bill without adding the prize.
        }
    }
};

class Stocker{
public:
    bool authorisation;//authorises the functions of this class to be used. 
    string shelf_select;//check your previous library on how to make small letters capital , check lm8 it might be there.
    bool assistance;//

    Stocker(){
        authorisation = false;
        shelf_select = 'aA';
        assistance = false;
    }

    bool authorising(){//authorises this class to be used in session.
        return authorisation = true;     
    }

    string selectShelf(){
        
        cout << "Enter the shelf code ";
        cin >> shelf_select;    
        return shelf_select; 
    }
};
class BusinessAnalytics{//more to add to the code will do that in the coming days 
public:
    bool autharise;//authorizes this function to be used. 
    double totalSales;// stores the total purchase made in a day. 
    int totalItemspurchased;//stores total items purchased
    /* 8 data fields to store the total items purchased. */ 
    double profits; 

    //creating a constructor for the class
    BusinessAnalytics(){
        autharise = false;
        totalSales = 0.00;
        totalItemspurchased = 0;
        profits = 0.00;
    }

    //Methods for this class

    bool authorazing(){
        
        return autharise = true;//authorises this class to be used in a session. 
    }

    double total_sales(int sale_per_Session){
        if(autharise){//if autharisation is set to true then the function runs. 
        totalSales +=sale_per_Session;
        return totalSales;// return the total sales after the prize per session
        }
        else{
            return totalSales;//return the original total sales after the prize per session. 
        }

    }
    /*For the Profits Method, I have to be really critical of this. I will do this after I have found how the code is going to work. */
};

 // Shelf function . 
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
  return ch = '_';
}
string correctshelfName(string shelfname){
  //The correctshelfName function corrects the users input of the shelf number to the standard harded format
  //to prevent runtime issues. 
  
  string tesf = "b1";//stores tesf. //the value inside is an arbitrarily value to make test print
   
   for(int i = 0; i <2; i++){

   //cout << chartoNum(test[i]) << " ";    
   tesf[i] = chartoNum(shelfname[i]);
  }
  //cout << tesf << endl;
  
  return tesf;

  //The customer class will use this when it is objectisied.

}

void myStore(){
    /*My store the program is the cashier right .
    And  in the store we have a customer and a stocker
    and a way to print the items in the store nicely and a shelf name so that when the user enters a specific value of the shelf 
    it can bring the items of the shelf then the user chooses the quantity he or she wants to buy. 
    */
   // create the customer and also the stocker. 
}

int main(){

    Stocker hello;
     hello.selectShelf();

    


    return 0;
}