namespace project2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void DrawGrid(object sender, PaintEventArgs e)
        {
            Color White = Color.White;
            Pen p = new Pen(White);
            p.Width = 8;
            e.Graphics.DrawLine(p, 100, 100, 100, 400);
            e.Graphics.DrawLine(p, 200, 100, 200, 400);
            e.Graphics.DrawLine(p, 300, 100, 300, 400);
            e.Graphics.DrawLine(p, 400, 100, 400, 400);

            e.Graphics.DrawLine(p, 100, 100, 400, 100);
            e.Graphics.DrawLine(p, 100, 200, 400, 200);
            e.Graphics.DrawLine(p, 100, 300, 400, 300);
            e.Graphics.DrawLine(p, 100, 400, 400, 400);

            p.Dispose();
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void GetTurn()
        {
            if (Convert.ToInt32(lbTurn.Tag) == 0)
            {
                lbTurn.Tag = 1;
                lbTurn.Text = "It's Now Player 1 turn";
            }
            else if (Convert.ToInt32(lbTurn.Tag) == 1)
            {
                lbTurn.Tag = 2;
                lbTurn.Text = "It's Now Player 2 turn";
            }
            else if (Convert.ToInt32(lbTurn.Tag) == 2)
            {
                lbTurn.Tag = 1;
                lbTurn.Text = "It's Now Player 1 turn";
            }
        }
        private void Lb_Click(object sender, EventArgs e)
        {
            GetTurn();
            if ((Convert.ToInt32(tbXOGrid.Tag) == 1) || Convert.ToInt32(tbXOGrid.Tag) == 0)
            {
                ((Label)sender).Text = "X";
                tbXOGrid.Tag = 2;
            }
            else {
                ((Label)sender).Text = "O";
                tbXOGrid.Tag = 1;
            }
            CheckWinner();
        }
        private bool Player1_Win_cases()
        {
            bool case1 = (lb1.Text == "X") && (lb2.Text == "X") && (lb3.Text == "X");
            bool case2 = (lb4.Text == "X") && (lb5.Text == "X") && (lb6.Text == "X");
            bool case3 = (lb7.Text == "X") && (lb8.Text == "X") && (lb9.Text == "X");
            
            bool case4 = (lb1.Text == "X") && (lb5.Text == "X") && (lb9.Text == "X");
            bool case5 = (lb3.Text == "X") && (lb5.Text == "X") && (lb7.Text == "X");

            bool case6 = (lb1.Text == "X") && (lb4.Text == "X") && (lb7.Text == "X");
            bool case7 = (lb2.Text == "X") && (lb5.Text == "X") && (lb8.Text == "X");
            bool case8 = (lb3.Text == "X") && (lb6.Text == "X") && (lb9.Text == "X");
            return case1 || case2 || case3 || case4 || case5 || case6 || case7 || case8; ;
        }

        private bool Player2_Win_cases()
        {
            bool case1 = (lb1.Text == "O") && (lb2.Text == "O") && (lb3.Text == "O");
            bool case2 = (lb4.Text == "O") && (lb5.Text == "O") && (lb6.Text == "O");
            bool case3 = (lb7.Text == "O") && (lb8.Text == "O") && (lb9.Text == "O");
                                                                                 
            bool case4 = (lb1.Text == "O") && (lb5.Text == "O") && (lb9.Text == "O");
            bool case5 = (lb3.Text == "O") && (lb5.Text == "O") && (lb7.Text == "O");
                                                                                 
            bool case6 = (lb1.Text == "O") && (lb4.Text == "O") && (lb7.Text == "O");
            bool case7 = (lb2.Text == "O") && (lb5.Text == "O") && (lb8.Text == "O");
            bool case8 = (lb3.Text == "O") && (lb6.Text == "O") && (lb9.Text == "O");
            return case1 || case2 || case3 || case4 || case5 || case6 || case7 || case8; ;
        }
        private void CheckWinner()
        {
            bool isPlayer1Won = Player1_Win_cases();
            bool isPlayer2Won = Player2_Win_cases();

            if (isPlayer1Won)
                lbTurn.Text = "Player 1 Won!, Click to reset";
            else if(isPlayer2Won)
                lbTurn.Text = "Player 2 Won!, Click to reset";
            if (!isPlayer1Won && !isPlayer2Won && (Convert.ToInt32(lbTurn.Tag) == 8))
                lbTurn.Text = "It's a draw";
        }
    }
}
