namespace RemainingExcercisesInCourse14
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnLong_Click(object sender, EventArgs e)
        {
            lblShow.Text = dateTimePicker1.Value.ToLongDateString();
        }

        private void btnShort_Click(object sender, EventArgs e)
        {
            lblShow.Text = dateTimePicker1.Value.ToShortDateString();
        }

        private void btnTime_Click(object sender, EventArgs e)
        {
            lblShow.Text = dateTimePicker1.Value.Hour.ToString();
        }

        private void btnDay_Click(object sender, EventArgs e)
        {
            lblShow.Text = dateTimePicker1.Value.Day.ToString();
        }

        private void btnMonth_Click(object sender, EventArgs e)
        {
            lblShow.Text = dateTimePicker1.Value.Month.ToString();
        }

        private void btnYear_Click(object sender, EventArgs e)
        {
            lblShow.Text = dateTimePicker1.Value.Year.ToString();
        }
    }
}
