namespace project2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            pictureBox1.Image = Image.FromFile("C:\\Users\\ayars\\Downloads\\tic-tac-toe.png");
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
        }
    }
}
