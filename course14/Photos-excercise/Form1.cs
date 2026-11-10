namespace Photos_excercise
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void update_photo(object sender, EventArgs e)
        {
            if (rbBoy.Checked)
                pictureBox1.Image = Image.FromFile("D:\\tech\\refining-my-basics\\Images\\Boy.png");
            else if (rbGirl.Checked)
                pictureBox1.Image = Image.FromFile("D:\\tech\\refining-my-basics\\Images\\Girl.png");
            else if (rbPen.Checked)
                pictureBox1.Image = Image.FromFile("D:\\tech\\refining-my-basics\\Images\\Pen.png");
            if (rbPencil.Checked)
                pictureBox1.Image = Image.FromFile("D:\\tech\\refining-my-basics\\Images\\Book.png");
        }
    }
}
