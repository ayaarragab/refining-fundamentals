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
    public partial class Form3 : Form
    {
        private int index = 0;
        public Form3()
        {
            InitializeComponent();
            listView1.LargeImageList = imageList1;
            listView1.SmallImageList = imageList1;
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedItem = View.List;
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (textBox1.Text.Length == 0 || textBox2.Text.Length == 0)
                return;
            ListViewItem item = new ListViewItem(textBox1.Text);
            item.ImageIndex = index % 2;
            ++index;
            item.SubItems.Add(textBox2.Text);
            listView1.Items.Add(item);
            textBox1.Clear();
            textBox2.Clear();
            textBox1.Focus();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
    switch (comboBox1.SelectedItem?.ToString())
    {
        case "Details":
            listView1.View = View.Details;
            break;

        case "List":
            listView1.View = View.List;
            break;

        case "Large Icons":
            listView1.View = View.LargeIcon;
            break;

        case "Small Icons":
            listView1.View = View.SmallIcon;
            break;

        case "Tile":
            listView1.View = View.Tile;
            break;
    }
        }
    }
}
