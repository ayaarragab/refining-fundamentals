using System.Reflection.Emit;

namespace FirstWindowsFormsApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            label3.Hide();
            textBox2.ReadOnly = true;
        }

        private void label1_Click(object sender, EventArgs e)
        {
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox2.Text = textBox1.Text;
        }

        private void preview_login_succ(object sender, EventArgs e)
        {
            if ((textBox1.Text.Length != 0) && (textBox2.Text.Length != 0))
            {
                label3.Show();
                label3.Text = "You've logged in successfully!!";
                button1.Enabled = false;
            }
            else
            {
                label3.Show();
                label3.Text = "Please enter fullName and password";
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox1.Enabled = false;
            textBox1.Enabled = false;
            button1.Enabled = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Hide();
            textBox2.Hide();
            button1.Hide();
            button2.Hide();
            button3.Hide();
            label2.Hide();
            label1.Hide();
            label3.Show();
            label3.Text = "Everything disappeared!";
        }
    }
}
