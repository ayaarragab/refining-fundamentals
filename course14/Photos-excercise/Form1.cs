namespace Photos_excercise
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            comboBox1.SelectedIndex = 0;
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void update_photo(object sender, EventArgs e)
        {
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.Text == "Boy")
                pictureBox1.Image = Image.FromFile("D:\\tech\\refining-my-basics\\Images\\Boy.png");
            else if (comboBox1.Text == "Girl")
                pictureBox1.Image = Image.FromFile("D:\\tech\\refining-my-basics\\Images\\Girl.png");
            else if (comboBox1.Text == "Pen")
                pictureBox1.Image = Image.FromFile("D:\\tech\\refining-my-basics\\Images\\Pen.png");
            if (comboBox1.Text == "Book")
                pictureBox1.Image = Image.FromFile("D:\\tech\\refining-my-basics\\Images\\Book.png");
        }
    }
}
