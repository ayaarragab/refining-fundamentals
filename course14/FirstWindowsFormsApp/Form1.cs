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
    }
}
