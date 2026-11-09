using System.Diagnostics;

namespace Project1
{
    public partial class Form1 : Form
    {
        private int _total_price = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged_1(object sender, EventArgs e)
        {

        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
        private void Update_Size_Label(object sender, EventArgs e)
        {
            lbSize.Text = "";
            if (rbSmall.Checked)
                lbSize.Text += rbSmall.Text;
            else if (rbMedium.Checked)
                lbSize.Text += rbMedium.Text;
            else if (rbLarge.Checked)
                lbSize.Text += rbLarge.Text;
            CalculateTotalPrices();
        }
        private void CalculateTotalPrices()
        {
            _total_price = 0;
            if (rbSmall.Checked)
            {
                _total_price += Convert.ToInt32(rbSmall.Tag);
            }
            else if (rbMedium.Checked)
            {
                _total_price += Convert.ToInt32(rbMedium.Tag);
            }
            else if (rbLarge.Checked)
            {
                _total_price += Convert.ToInt32(rbLarge.Tag);
            }

            if (chExtrach.Checked)
            {
                _total_price += Convert.ToInt32(chExtrach.Tag);
            }
            if (chMush.Checked)
            {
                _total_price += Convert.ToInt32(chMush.Tag);
            }
            if (chTom.Checked)
            {
                _total_price += Convert.ToInt32(chTom.Tag);
            }

            if (rbThick.Checked)
            {
                _total_price += Convert.ToInt32(rbThick.Tag);
            }
            else if (rbThin.Checked)
            {
                _total_price += Convert.ToInt32(rbThin.Tag);
            }

            if (rbEatIn.Checked)
            {
                _total_price += Convert.ToInt32(rbEatIn.Tag);
            }
            else if (rbEatOut.Checked)
            {
                _total_price += Convert.ToInt32(rbEatOut.Tag);
            }
            lbTotalPrice.Text = _total_price.ToString();
        }

        private void updateToppings(object sender, EventArgs e)
        {
            lbToppings.Text = "";
            if (chExtrach.Checked)
                lbToppings.Text += chExtrach.Text;
            else if (chMush.Checked)
                lbToppings.Text += chMush.Text;
            else if (chTom.Checked)
                lbToppings.Text += chTom.Text;
            CalculateTotalPrices();
        }

        private void update_crust(object sender, EventArgs e)
        {
            lbCrustType.Text = "";
            if (rbThick.Checked)
                lbCrustType.Text += rbThick.Text;
            else if (rbThin.Checked)
                lbCrustType.Text += rbThin.Text;
            CalculateTotalPrices();
        }

        private void update_eat_where(object sender, EventArgs e)
        {
            lbWhereToEat.Text = "";
            if (rbEatIn.Checked)
                lbWhereToEat.Text += rbEatIn.Text;
            else if (rbEatOut.Checked)
                lbWhereToEat.Text += rbEatOut.Text;
            CalculateTotalPrices();
        }
    }
}
