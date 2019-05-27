#include <iostream>
#include <ctime>
#include <vector>
#include "Date.h"
using namespace std;

class Message{
protected:
    string myContent;
    Date myDate;
public:
    Message(string content) {
        this->myContent = content;
        this->myDate = Date();
    }
    void displayContent(void) const {
        cout << this->myContent;
    }
    Date getDate(void)const {
        return this->myDate;
    }
};

class PublicMessage : public Message{
private:
    unsigned myLikers = 0;
public:
    PublicMessage (string msg) : Message(msg)  {}
    void add(void){
        this->myLikers += 1;
    }

    unsigned getNbLikers(void) const{
        return this->myLikers;
    }
};

class User;
class PrivateMessage : public Message {
private:
    User* mySender;
public:
    PrivateMessage(string msg, User* sender) : Message (msg){
        this->mySender = sender;
    }

    User* getSender(){
        return this->mySender;
    }
};

void displayDate (const Date & date)
{
    cout << date.getDay () << "/" << date.getMonth () << "/" << date.getYear ();

}
void displayHour (const Date & date)
{
    cout << date.getHour () << "h " << date.getMin ()
         << "mn et " << date.getSec() << "sec";
}
class System;
class User
{
private:
    string myName;
    unsigned myNumber;
    vector<User*> myFriend;
    vector<PrivateMessage> myMessagesSent;
    vector<PrivateMessage*> myMessageReceive;

public :
    User(string name){
        this->myName = name;
    }
   void sendMessage (PrivateMessage* message)
   {
       this->myMessageReceive.push_back(message);
       cout << endl;
   } // sendMessage()
   void addFriend (User * oneFriend) {
       this->myFriend.push_back(oneFriend);
       cout << "ajouté" << endl;
   }
   User * getFriend (unsigned i) const {
       cout << i << endl;
       return myFriend[i];
   }
   string getName() const{
        return this->myName;
   }
   System * getSystem (void) const {
       cout << "système" << endl; return NULL;
   }
   void addMessage (PrivateMessage & message) {
       message.displayContent ();
       this->myMessagesSent.push_back(message);
       message.getSender()->sendMessage(&message);
       cout << endl;
   }
   unsigned getNbSentMessages(){
    return this->myMessagesSent.size();
   }

   unsigned getNbRecievedMessages(){
    return this->myMessageReceive.size();
   }

   unsigned getNbFriends(){
        return this->myFriend.size();
   }

   PrivateMessage* getRecievedMessage(unsigned i){
        return this->myMessageReceive[i];
   }

   PrivateMessage getSentMessage(unsigned i){
        return this->myMessagesSent[i];
   }
}; // User

void testPrivateMessage (void)
{
    User user("test");
    PrivateMessage message ("salut", & user);
    message.displayContent ();
    cout << " posté le : ";
    displayDate (message.getDate ());
    cout << " à ";
    displayHour (message.getDate ());
    cout << endl;
    message.getSender ()->getFriend (5);

} // testPrivateMessage()

void testMessage (void)
    {
        Message message ("salut");
        message.displayContent ();
        cout << " posté le : ";
        displayDate (message.getDate ());
        cout << " à ";
        displayHour (message.getDate ());
        cout << endl;

    } // testMessage()}

void testPublicMessage (void)
{
    PublicMessage message ("salut");
    message.displayContent ();
    cout << " posté le : ";
    displayDate (message.getDate ());
    cout << " à ";
    displayHour (message.getDate ());
    cout << endl;
    for (unsigned i(0); i < 5; ++i)
        message.add ();
    cout << "Nb de likers : " << message.getNbLikers () << endl;

} // testPublicMessage()

void testUser (void)
    {
       // System oneSystem;
        User alfred    ("Alfred");
        User alain     ("Alain");
        User sophie    ("Sophie");
        User emmanuel  ("Emmanuel");
        User christian ("Christian");
        User petru     ("Petru");
        User marc      ("Marc");
        PrivateMessage message ("salut", & alfred);
        message.displayContent ();
        cout << endl;

        alain.addFriend (&sophie);
        alain.addFriend (&emmanuel);
        alain.addFriend (&christian);
        alain.addFriend (&petru);
        alain.addFriend (&marc);

        cout << "Alain a " << alain.getNbFriends () << " amis" << endl;
        cout << "Le troisième ami d'Alain est : " << (alain.getFriend (2))->getName() << endl;

        alfred.addMessage (message);
        alain.sendMessage (&message);
        cout << "Nombre de message envoyés par Alfred : " << alfred.getNbSentMessages ()   << endl;
        cout << "Nombre de message reçus par Alfred : " << alfred.getNbRecievedMessages () << endl;
        cout << "Nombre de message envoyés par Alain : " << alain.getNbSentMessages ()   << endl;
        cout << "Nombre de message reçus par Alain : " << alain.getNbRecievedMessages () << endl;
        alain.getRecievedMessage (0)->displayContent ();
        cout << endl;
        alfred.getSentMessage (0).displayContent ();
        cout << endl;

    } // testUser()

class System {
    private:
    unsigned myNbUsers;
    unsigned myNbMessages;

    vector<PublicMessage> myPublicMessages;
    vector<User> myUsers;
public:
    System (void) : myNbUsers (0), myNbMessages (0)
    {
        myUsers.reserve (1000);
        myPublicMessages.reserve (1000);
        // création des Users
        addUser ("Alfred");
        addUser ("Alain");
        addUser ("Sophie");
        addUser ("Emmanuel");
        addUser ("Christian");
        addUser ("Petru");
        addUser ("Marc");
        /* verification des Users */
        cout << myUsers.size () << endl;
        for (const User & user : myUsers)
        {
            cout << user.getName () << endl;
        }

        for (unsigned i (0); i < myUsers.size (); ++i)
            for (unsigned j (0); j < myUsers.size () / 2; ++j)
                myUsers [i].addFriend (&myUsers [(i + ((j * 2) + 1)) % myUsers.size ()]);
        for (unsigned i (0); i < myUsers.size (); ++i)
        {
            User user = myUsers [i];
            cout << user.getName () << " a " << user.getNbFriends() << " amis : " << endl;
            for (unsigned j (0); j < user.getNbFriends (); ++j)
                cout << (user.getFriend (j))->getName () << endl;
        }
        for (User & user : myUsers)
        {
            for (unsigned j (0); j < user.getNbFriends (); ++j)
            {
                string content (string ("salut") + ' ' + (user.getFriend (j))->getName ());
                PrivateMessage message (content, & user);
                user.addMessage (message);
                PrivateMessage tmp = user.getSentMessage (user.getNbSentMessages () - 1);
                (user.getFriend (j))->sendMessage (&tmp);
            }
        }

        for (unsigned i (0); i < myUsers.size (); ++i)
        {
            User user = myUsers [i];
            cout << user.getName () << " a envoyé " << user.getNbSentMessages() << " messages : " << endl;
            for (unsigned j (0); j < user.getNbSentMessages (); ++j)
            {
                (user.getSentMessage (j)).displayContent();
                cout << endl;
            }

        }
        for (unsigned i (0); i < myUsers.size (); ++i)
        {
            User user = myUsers [i];
            cout << user.getName () << " a reçu " << user.getNbRecievedMessages() << " messages : " << endl;
            for (unsigned j (0); j < user.getNbRecievedMessages (); ++j)
            {
                cout << "de " << (user.getRecievedMessage (j))->getSender ()->getName () << " : ";
                (user.getRecievedMessage (j))->displayContent();
                cout << endl;
            }

        }
        string oneMessage ("a");
        for (const User & user : myUsers)
            for (unsigned i (0); i < 5; ++i)
            {
                oneMessage += 'a';
                (user.getSystem ())->addPublicMessage (oneMessage);
            }
        for (const PublicMessage & message : myPublicMessages)
        {
            message.displayContent ();
            cout << endl;
        }
        for (User & user : myUsers)
            for (unsigned i (0); i < myNbMessages; ++i)
                (user.getSystem ())->getPublicMessage (i).add ();

        for (PublicMessage & message : myPublicMessages)
        {
            message.displayContent ();
            cout << " a " << message.getNbLikers () << " likers" << endl;
        }
/*    */

     } // System()
    User* getUser(unsigned i){
        return &this->myUsers[i];
    }
    PublicMessage getPublicMessage(unsigned i){
        return this->myPublicMessages[i];
    }
    void addUser(string name){
        User user(name);
        this->myUsers.push_back(user);
    }
    void addPublicMessage(string message){
        PublicMessage m(message);
        this->myPublicMessages.push_back(m);
    }
};

int main()
{
    System();
    return 0;
}
