#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Plane
{
    public:
    Plane(const std::string name){m_name = name;};
    ~Plane(){};
    
    std::string typeIs() const {return m_type;};
    
    void receiveMsg1(const Plane *msgSenderPlane, const std::string& message) const
    {
        std::cout << msgSenderPlane->m_name << " plane sent a message to plane "
            << m_name << ", and the message is: " << message << std::endl;
    };
    void receiveMsg2(const Plane *msgSenderPlane, const std::string& message) const
    {
        std::cout << msgSenderPlane->m_name << " / " << m_name << 
            " / " << message << std::endl;
    };
    void receiveMsg3(const Plane *msgSenderPlane, const std::string& message) const
    {
        std::cout << "what is happening???" << std::endl;
    };
    
    void receiveMsg4(const Plane *msgSenderPlane, const std::string& message) const
    {
        std::cout << (msgSenderPlane->m_name+m_name+message) << std::endl;
    };

    protected:
    std::string m_type;

    private:
    std::string m_name;
};

class Helicopter : public Plane
{
    public:
    Helicopter(const std::string name):Plane(name){m_type = "Helicopter";};
    ~Helicopter(){};
};

class Glider : public Plane
{
    public:
    Glider(const std::string name):Plane(name){m_type = "Glider";};
    ~Glider(){};
};

class ATC
{
    public:
    ATC(){};
    ~ATC(){};
    
    void addPlane(const Plane *pPlane)
    {
        m_listOfPlanes.push_back(pPlane);
    };
    
    void messagePlane(const Plane *msgSenderPlane, const Plane *msgReceiverPlane, 
        const std::string& message)
        {
            if(msgSenderPlane->typeIs() == "Glider" && msgReceiverPlane->typeIs() == "Glider")
            {
                msgReceiverPlane->receiveMsg1(msgSenderPlane, message);
            }
            else if(msgSenderPlane->typeIs() == "Glider" && msgReceiverPlane->typeIs() == "Helicopter")
            {
                msgReceiverPlane->receiveMsg2(msgSenderPlane, message);
            }
            else if(msgSenderPlane->typeIs() == "Helicopter" && msgReceiverPlane->typeIs() == "Glider")
            {
                msgReceiverPlane->receiveMsg3(msgSenderPlane, message);
            }
            else if(msgSenderPlane->typeIs() == "Helicopter" && msgReceiverPlane->typeIs() == "Helicopter")
            {
                msgReceiverPlane->receiveMsg4(msgSenderPlane, message);
            }
        };

    private:
    std::vector<const Plane*> m_listOfPlanes;
};

int main()
{
    Plane *plane_01 = new Glider("glider_01");
    Plane *plane_02 = new Glider("glider_02");
    Plane *plane_03 = new Glider("glider_03");
    Plane *plane_04 = new Helicopter("helipcopter_01");
    Plane *plane_05 = new Helicopter("helipcopter_02");
    Plane *plane_06 = new Helicopter("helipcopter_03");
    
    ATC atc;
    atc.addPlane(plane_01);
    atc.addPlane(plane_02);
    atc.addPlane(plane_03);
    atc.addPlane(plane_04);
    atc.addPlane(plane_05);
    atc.addPlane(plane_06);

    atc.messagePlane(plane_01, plane_06, "this is the first message");
    atc.messagePlane(plane_03, plane_02, "this is the second message");
    atc.messagePlane(plane_05, plane_04, "this is the third message");
    atc.messagePlane(plane_06, plane_03, "this is the fourth message");

    return 0;
}
