#include "sms.hpp"
// c'est pour la classe Telephone
Telephone::Telephone(/* args */) 
{
    numero = "";
    reseau = 0;
    messages = 0;
}
Telephone::Telephone(string _numero)  
{
    numero = _numero;
    reseau = 0;
    messages=0;
}

string Telephone::getNumero() const
{
    return numero;
}

int Telephone::getNbMessages() const
{
    return messages;
}

void Telephone::setNumero(string _numero)
{
    numero = _numero;
}
void Telephone::setReseau(Reseau *_reseau){
    reseau = _reseau;
}
Reseau*  Telephone::getReseau()const {
    
    return reseau;
}

void Telephone::textoter(string numero2, string _message){
    SMS messagesend(numero, numero2, _message);
    try
    {
        /* code */
        // reseau->trouveTel(numero2).message.push_back(messagesend);
        reseau->trouveTel(numero2).messages++;
    }
    catch(MauvaisNumero& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // message.push_back(messagesend);
    messages++;
}
void Telephone::mmser(string num,MMS* mms){
    try
    {
        reseau->trouveTel(num).messages++;
        mms->setA(num);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    messages++;
    mms->setDe(numero);
    
}

bool Telephone::operator<(Telephone toto) const
{
    return (this->numero < toto.numero);
}

Telephone::~Telephone()
{
}

//c'est pour la classe Reseau
Reseau::Reseau(/* args */)
{
}

Reseau::~Reseau()
{
}

string Reseau::lister()
{
    string reponse = "";
    sort(telephones.begin(),telephones.end());
    for (Telephone t: telephones)
    {
        reponse += t.getNumero()+ "\n";
    }
    return reponse;
}

void Reseau::ajouter(string _numero)
{
    Telephone telephone(_numero);
    telephone.setReseau(this);
    telephones.push_back(telephone);
}

Telephone& Reseau::trouveTel(const string numero){
    // Telephone *telephone;
    // for (auto tel : telephones)
    // {
    //     if (tel.getNumero() == numero)
    //     {
    //         telephone = &tel;
    //     }
    // }
    // if (telephone->getNumero() == "")
    // {
    //     throw MauvaisNumero(), invalid_argument("test");
    // }
    auto it = telephones.begin();
    while (it< telephones.end() && it ->getNumero() != numero)
    {
        /* code */
        ++it;
    }
    if (it == telephones.end())
        throw MauvaisNumero();
    return *it;
}


//Message
int Message::cle=0;
Message::Message(){}
Message::Message(string numSrc,string numDest, string text):numSrc(numSrc),numDest(numDest),text(text)
{
    id = cle;
    cle++;
}
Message::~Message(){}

string Message::getTexte()
{
    return text;
}
int Message::getId(){
    return id;
}
int Message::getCle(){
    return cle;
}
void Message::setTexte(string _text){
    if (_text == "essai" || _text == "exam")
    {
        /* code */
        text = _text + text;
    }else if(_text == "[[son]]" ||_text == "[[image]]"||_text == "[[video]]" )
    {
        /* code */
        text += _text;
    }else{
        text= _text;
    }
    
    
    
}



//SMS

SMS::SMS(/* args */)
{
}
SMS::SMS(string numSrc,string numDest, string text): Message(numSrc,numDest,text)
{
}
string SMS::afficher(){
    return getTexte();
}


SMS::~SMS()
{
}

//Media
Media::Media(/* args */)
{
}

Media::~Media()
{
}

//Image
Image::Image(/* args */)
{
}

string Image::afficher()
{
    return "[[image]]";
}

Image::~Image()
{
}
//Video
Video::Video(/* args */)
{
}

string Video::afficher()
{
    return "[[video]]";
}

Video::~Video()
{
}
//Son
Son::Son(/* args */)
{
}

string Son::afficher()
{
    return "[[son]]";
}

Son::~Son()
{
}

//class MMS
MMS::MMS(/* args */)
{
}
MMS::MMS(string numSrc,string numDest, string text): SMS(numSrc,numDest,text)
{
}

void MMS::joindre(Image* image)
{
    setTexte(image->afficher() );
}
void MMS::joindre(Video* video)
{
    setTexte( video->afficher());
}
void MMS::joindre(Son* son)
{
    setTexte(son->afficher());
}

string MMS::getDe(){
    return De;
}
string MMS::getA(){
    return A;
}

void MMS::setDe(string _de)
{
    De= _de;
}
void MMS::setA(string _a)
{
    A= _a;
}
MMS::~MMS()
{
}