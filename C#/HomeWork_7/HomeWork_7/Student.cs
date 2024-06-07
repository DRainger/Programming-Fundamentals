using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HomeWork_7
{
    internal class Student
    {
        string _id;
        string _name;
        int _age;
        public Student(string id,string name,int age) 
        {
            _age = age;
            _id = id;
            _name = name;
        }
        public string get_id() { return _id; }
        public int get_age () { return _age;}
        public string get_name () { return _name;}   
        public void set_name (string name) { _name = name;}
        public void set_id (string id) { _id = id; }
        public void set_age (int age) {  _age = age; }
        public string toString() { return $"name: {_name}, id:{_id}, age:{_age}"; }
    }
}
