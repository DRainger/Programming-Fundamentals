using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HomeWork_7
{
    internal class Grades
    {
        string _id;
        int _cid;
        int _cgrade;
        public Grades(string id,int cid,int grade)
        {
            _id = id;
            _cid = cid;
            _cgrade = grade;
        }
        public string get_id() { return _id; }
        public int get_cid() { return _cid; }
        public int getCgrade() { return _cgrade; }
        public void set_id (string id) { _id = id;}
        public void set_cid (int cid) { _cid = cid;}
        public void set_cgrade (int grade) { _cgrade = grade;}
    }
}
