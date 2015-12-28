#include "MessageFolder.h"

using namespace std;

Folder& Folder::operator=(const Folder& rhs){
    removeFromMessages();
    messages = rhs.messages;
    addToMessages();
    return *this;
}

Folder::Folder(Folder&& rhs){
    messages = std::move(rhs.messages);
    for(const auto& m : messages){
        m->addFol(this); //this could throw exception
        m->remFol(&rhs);
    }
    rhs.messages.clear();
}

Folder& Folder::operator=(Folder&& rhs){
    if(this != &rhs){
        removeFromMessages();
        messages = std::move(rhs.messages);
        for(const auto& m : messages){
            m->addFol(this); //this could throw exception
            m->remFol(&rhs);
        }
        rhs.messages.clear();
    }
    return *this;
}

std::ostream& Folder::printAll(std::ostream& os){
    for(const auto& m : messages){
        os << (m->contents) << endl;
    }
    return os;
}

void Folder::addToMessages(){
    for(const auto& m : messages)
        m->addFol(this);
}

void Folder::removeFromMessages(){
    for(const auto& m : messages)
        m->remFol(this);
}

void swap(Folder& lhs, Folder& rhs){
    lhs.removeFromMessages();
    rhs.removeFromMessages();
    using std::swap;
    swap(lhs.messages, rhs.messages);
    lhs.addToMessages();
    rhs.addToMessages();
}

Message& Message::operator=(const Message& rhs){
    removeFromFolders();
    contents = rhs.contents;
    folders = rhs.folders;
    addToFolders();
    return *this;
}

Message::Message(Message&& rhs): contents(std::move(rhs.contents)) {
    folders = std::move(rhs.folders);
    for(const auto& f : folders){
        f->addMsg(this);
        f->remMsg(&rhs);
    }
    rhs.folders.clear();

}

Message& Message::operator=(Message&& rhs){

    if(this != &rhs){
        removeFromFolders();
        contents = std::move(rhs.contents);
        folders = std::move(rhs.folders);
        for(const auto& f : folders){
            f->addMsg(this);
            f->remMsg(&rhs);
        }
        rhs.folders.clear();
    }
    return *this;

}

Message& Message::save(Folder& f){
    addFol(&f);
    f.addMsg(this);
    return *this;
}

Message& Message::remove(Folder& f){
    remFol(&f);
    f.remMsg(this);
    return *this;
}


void Message::addToFolders(){
    for(const auto& f : folders)
        f->addMsg(this);
}

void Message::removeFromFolders(){
    for(const auto& f : folders)
        f->remMsg(this);
}

void swap(Message& lhs, Message& rhs){
    lhs.removeFromFolders();
    rhs.removeFromFolders();
    using std::swap;
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    lhs.addToFolders();
    rhs.addToFolders();
}


