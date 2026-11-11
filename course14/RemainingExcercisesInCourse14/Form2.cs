using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RemainingExcercisesInCourse14
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            progressBar1.Maximum = 100;
            progressBar1.Minimum = 10;
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (progressBar1.Value == 100)
            {
                return;
            }
            progressBar1.Value += 10;
            Thread.Sleep(500);
            label1.Text = (((float)progressBar1.Value / progressBar1.Maximum) * 100).ToString();
        }
    }
}
