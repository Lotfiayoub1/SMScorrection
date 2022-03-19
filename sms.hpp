#ifndef __SMS
#define __SMS

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

using namespace std;
class Reseau;
class SMS;
class MMS;

class Telephone
{
    private:
        /* data */
        string numero;
        Reseau* reseau;
        // vector<SMS> message;
        int messages; 
    public:
        string getNumero() const;
        int getNbMessages() const;
        Reseau* getReseau() const;
        void setNumero(string _numero);
        void setReseau(Reseau *_reseau);
        void mmser(string,MMS*);
        void textoter(string numero, string messsage);
        bool operator<(Telephone tele) const;
        Telephone(/* args */) ;
        Telephone(string _numero);
        ~Telephone();
};

//Classe pour les exceptions
class MauvaisNumero : public std::exception
{
    public:
        virtual const char * what() const throw()
        {
            return "mauvais numero";
        }
};
//Class Réseau
class Reseau
{
    private:
        /* data */
        vector<Telephone> telephones; 
    public:
        
        string lister();
        void ajouter(string numero);
        Telephone& trouveTel(const string numero);
        Reseau(/* args */);
        ~Reseau();
};


class Message
{
    private:
    /* data */
        string numSrc;
        string numDest;
        string text;
        int id;
        static int cle; 
    public:
        Message(/* args */);
        Message(string,string, string);
        virtual string afficher()=0;
        int getId();
        string getTexte();
        static int getCle();
        void setTexte(const string );
        virtual ~Message();
};






//Class SMS

class SMS : public Message
{
    private:
        
    public:
        SMS(/* args */);
        SMS(string numSrc,string numDest, string test);
        
        
        virtual string afficher();

        ~SMS();
};



class Media
{
private:
    /* data */
public:
    Media(/* args */);
    virtual string afficher()=0;
    virtual ~Media();
};

class Image: public Media
{
private:
    /* data */
public:
    Image(/* args */);
    string afficher();
    ~Image();
};




class Video: public Media
{
private:
    /* data */
public:
    Video(/* args */);
    string afficher();
    ~Video();
};
class Son: public Media
{
private:
    /* data */
public:
    Son(/* args */);
    string afficher();
    ~Son();
};



class MMS : public SMS
{
private:
    /* data */
    string De;
    string A;
public:
    MMS(/* args */);
    MMS(string numSrc,string numDest, string test);
    void joindre(Image* image );
    void joindre(Video* video );
    string getDe();
    string getA();
    void setDe(string _de);
    void setA(string _a);
    void joindre(Son* son );
    ~MMS();
};






#endif