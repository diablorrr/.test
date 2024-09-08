#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
using std::string;
#include <set>
using std::set;

class Folder;

class Message {
        friend void swap(Message &, Message &);
        friend void swap(Folder &, Folder &);
        friend class Folder;
    public:
        explicit Message(const string &str = ""):
            contents(str) {}
        Message(const Message&);
        Message& operator=(const Message&);
        ~Message();
        void save(Folder&);
        void remove(Folder&);
        void print_debug();

        Message(Message &&) noexcept;
        Message& operator=(Message &&);
    private:
        string contents;
        set<Folder*> folders;

        void add_to_Folders(const Message&);
        void remove_from_Folders();

        void addFldr(Folder *f) {folders.insert(f);}
        void remFlddr(Folder *f) {folders.erase(f);}
};

void swap(Message &, Message &);


class Folder {
        friend void swap(Message &, Message &);
        friend void swap(Folder &, Folder &);
        friend class Message;
    public:
        Folder() = default;
        Folder(const Folder&);
        Folder& operator=(const Folder&);
        ~Folder();
        void print_debug();
    private:
        set<Message*> msgs;

        void add_to_Message(const Folder&);
        void remove_to_Message();

        void addMsg(Message *m) {msgs.insert(m);}
        void remMsg(Message *m) {msgs.erase(m);}
};

void swap(Folder &, Folder &);
#endif
