using System.Reflection.Emit;

namespace FirstWindowsFormsApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            label3.Hide();
        }

        private void label1_Click(object sender, EventArgs e)
        {
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            label4.Text = textBox1.Text;
        }

        private void preview_login_succ(object sender, EventArgs e)
        {
            if ((textBox1.Text.Length != 0) && (textBox2.Text.Length != 0) && ((checkBox1.Checked) || (checkBox2.Checked)))
            {
                label3.Show();
                string remaining_label_text = $"{(checkBox1.Checked ? checkBox1.Text : "") + (checkBox2.Checked ? $"And {checkBox2.Text}" : "")}\n";
                label3.Text = $"Your name is {textBox1.Text} and your password is {textBox2.Text} and you write code in " + remaining_label_text;
                button1.Enabled = false;
            }
            else
            {
                label3.Show();
                label3.Text = "Please enter fullName and password";
            }
            if (!checkBox1.Checked && !checkBox2.Checked)
                label3.Text += "\nPlease Choose a programming language\n";
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

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}
