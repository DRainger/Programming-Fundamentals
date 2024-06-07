using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HomeWork_7
{
    internal class Course
    {
        int _c_id;
        string _c_name;
        public Course(int c_id, string c_name)
        {
            _c_id = c_id;
            _c_name = c_name;
        }
        public int get_c_id() { return _c_id; }
        public string get_c_name() {  return _c_name; }
        public void set_c_id (int id) { _c_id = id; }
        public void set_c_name (string c_name) { _c_name = c_name;}
    }
}
