#ifndef MESSAGEFOLDER
#define MESSAGEFOLDER

#include <string>
#include <set>
#include <iostream>

/*There is a problem in this code with const functions. Since Messages defines a set of non-const Folders and Folders defines
a set of non-const Messages we should not use const-objects. We can construct a const Message object using the copy-constructor
but it would be in error as its pointer would be stored in a set<Message*>, losing lower-level const. */

class Message;

class Folder{
    friend class Message;
    friend void swap(Folder&, Folder&);
public:
    Folder() { }
    Folder(const Folder& rhs): messages(rhs.messages) { addToMessages(); }
    Folder& operator=(const Folder& rhs);
    Folder(Folder&&);
    Folder& operator=(Folder&&);
    ~Folder() { removeFromMessages(); }
    std::ostream& printAll(std::ostream&);
private:
    std::set<Message*> messages;
    void addMsg(Message* m) { messages.insert(m); } //these two are used by Messages class to update Folders containing the messages
    void remMsg(Message* m) { messages.erase(m); }
    void addToMessages(); //these are used by copy-control and swap
    void removeFromMessages();
};

void swap(Folder&, Folder&);

class Message{
    friend class Folder;
    friend void swap(Message&, Message&);
public:
    Message(const std::string &s = ""): contents(s) { }
    Message(const Message& rhs): contents(rhs.contents), folders(rhs.folders) { addToFolders(); }
    Message& operator=(const Message& rhs);
    Message(Message&&);
    Message& operator=(Message&&);
    ~Message() { removeFromFolders(); }
    Message& save(Folder&); //public use to remove/add to folder
    Message& remove(Folder&);
    std::ostream& print(std::ostream& os) { os << contents << std::endl; return os;}
private:
    std::string contents;
    std::set<Folder*> folders;
    void addFol(Folder* f) { folders.insert(f); } //these two are used by Folders class to update Messages contained by the folders
    void remFol(Folder* f) { folders.erase(f); }
    void addToFolders(); //these are used by copy-control and swap
    void removeFromFolders();
};

void swap(Message&, Message&);

#endif // MESSAGEFOLDER
