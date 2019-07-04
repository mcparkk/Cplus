#include <QCoreApplication>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDomElement>
#include <iostream>
#include <QString>
#include <string>


void save_xml()
{
    QFile file("test.xml");
    if(!file.open(QFile::WriteOnly | QFile::Text))
        return ;
    else{
        QXmlStreamWriter xwrite;
        xwrite.setDevice(&file);
        xwrite.setAutoFormatting(true);

        xwrite.writeStartDocument();
//        xwrite.writeDTD("<test xml>");          //정보

        xwrite.writeComment("xml test code");     //주석

        xwrite.writeStartElement("empinfo");
        xwrite.writeStartElement("employees");

        xwrite.writeStartElement("employee");
        xwrite.writeAttribute("name", "James");
        xwrite.writeAttribute("age","40");
        xwrite.writeEndElement(); //employee

        xwrite.writeStartElement("employee");
        xwrite.writeAttribute("name", "Jean");
        xwrite.writeAttribute("age","45");
        xwrite.writeEndElement(); //employee
        \
        xwrite.writeStartElement("employee");
        xwrite.writeAttribute("name", "Wesley");
        xwrite.writeAttribute("age","27");
        xwrite.writeEndElement(); //employee

        xwrite.writeEndElement(); //employees
        xwrite.writeEndElement(); //enpinfo

        xwrite.writeEndDocument();

        file.close();
    }

}

using namespace std;

int main()
{
    save_xml();
    QFile file("test.xml");

    QDomDocument doc;
    QString errorStr;
    if(!doc.setContent(&file, true, &errorStr))
    {
        cout << errorStr.toLocal8Bit().constData() << endl;
    }
    QDomElement root = doc.documentElement();
    QDomElement employees = root.firstChildElement();
    QDomElement employee = employees.firstChildElement();

    while(!employee.isNull())
    {
        cout << employee.attribute("age").toStdString() << endl;
        employee = employee.nextSiblingElement();
    }
}
