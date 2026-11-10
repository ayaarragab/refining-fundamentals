namespace project2
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            label1 = new Label();
            tbXOGrid = new TableLayoutPanel();
            lb9 = new Label();
            lb8 = new Label();
            lb7 = new Label();
            lb6 = new Label();
            lb5 = new Label();
            lb4 = new Label();
            lb3 = new Label();
            lb1 = new Label();
            lb2 = new Label();
            lbTurn = new Label();
            tbXOGrid.SuspendLayout();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("High Tower Text", 28.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label1.ForeColor = SystemColors.ButtonHighlight;
            label1.Location = new Point(22, 20);
            label1.Name = "label1";
            label1.Size = new Size(754, 55);
            label1.TabIndex = 0;
            label1.Text = "Welcome to my Tic Tac Toe Game";
            label1.Click += label1_Click;
            // 
            // tbXOGrid
            // 
            tbXOGrid.CellBorderStyle = TableLayoutPanelCellBorderStyle.OutsetDouble;
            tbXOGrid.ColumnCount = 3;
            tbXOGrid.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 33.3333359F));
            tbXOGrid.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 33.3333244F));
            tbXOGrid.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 33.3333321F));
            tbXOGrid.Controls.Add(lb9, 2, 2);
            tbXOGrid.Controls.Add(lb8, 1, 2);
            tbXOGrid.Controls.Add(lb7, 0, 2);
            tbXOGrid.Controls.Add(lb6, 2, 1);
            tbXOGrid.Controls.Add(lb5, 1, 1);
            tbXOGrid.Controls.Add(lb4, 0, 1);
            tbXOGrid.Controls.Add(lb3, 2, 0);
            tbXOGrid.Controls.Add(lb1, 0, 0);
            tbXOGrid.Controls.Add(lb2, 1, 0);
            tbXOGrid.ForeColor = SystemColors.ButtonHighlight;
            tbXOGrid.Location = new Point(193, 121);
            tbXOGrid.Name = "tbXOGrid";
            tbXOGrid.RowCount = 3;
            tbXOGrid.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3333359F));
            tbXOGrid.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3333359F));
            tbXOGrid.RowStyles.Add(new RowStyle(SizeType.Percent, 33.3333359F));
            tbXOGrid.Size = new Size(300, 300);
            tbXOGrid.TabIndex = 1;
            tbXOGrid.Tag = "0";
            tbXOGrid.Paint += tableLayoutPanel1_Paint;
            // 
            // lb9
            // 
            lb9.AutoSize = true;
            lb9.Font = new Font("Segoe UI", 36F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lb9.Location = new Point(220, 201);
            lb9.Margin = new Padding(20, 0, 0, 30);
            lb9.Name = "lb9";
            lb9.Size = new Size(61, 66);
            lb9.TabIndex = 8;
            lb9.Text = "?";
            lb9.Click += Lb_Click;
            // 
            // lb8
            // 
            lb8.AutoSize = true;
            lb8.Font = new Font("Segoe UI", 36F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lb8.Location = new Point(122, 201);
            lb8.Margin = new Padding(20, 0, 0, 30);
            lb8.Name = "lb8";
            lb8.Size = new Size(61, 66);
            lb8.TabIndex = 7;
            lb8.Text = "?";
            lb8.Click += Lb_Click;
            // 
            // lb7
            // 
            lb7.AutoSize = true;
            lb7.Font = new Font("Segoe UI", 36F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lb7.Location = new Point(23, 201);
            lb7.Margin = new Padding(20, 0, 0, 30);
            lb7.Name = "lb7";
            lb7.Size = new Size(61, 66);
            lb7.TabIndex = 6;
            lb7.Text = "?";
            lb7.Click += Lb_Click;
            // 
            // lb6
            // 
            lb6.AutoSize = true;
            lb6.Font = new Font("Segoe UI", 36F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lb6.Location = new Point(220, 102);
            lb6.Margin = new Padding(20, 0, 0, 30);
            lb6.Name = "lb6";
            lb6.Size = new Size(61, 66);
            lb6.TabIndex = 5;
            lb6.Text = "?";
            lb6.Click += Lb_Click;
            // 
            // lb5
            // 
            lb5.AutoSize = true;
            lb5.Font = new Font("Segoe UI", 36F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lb5.Location = new Point(122, 102);
            lb5.Margin = new Padding(20, 0, 0, 30);
            lb5.Name = "lb5";
            lb5.Size = new Size(61, 66);
            lb5.TabIndex = 4;
            lb5.Text = "?";
            lb5.Click += Lb_Click;
            // 
            // lb4
            // 
            lb4.AutoSize = true;
            lb4.Font = new Font("Segoe UI", 36F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lb4.Location = new Point(23, 102);
            lb4.Margin = new Padding(20, 0, 0, 30);
            lb4.Name = "lb4";
            lb4.Size = new Size(61, 66);
            lb4.TabIndex = 3;
            lb4.Text = "?";
            lb4.Click += Lb_Click;
            // 
            // lb3
            // 
            lb3.AutoSize = true;
            lb3.Font = new Font("Segoe UI", 36F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lb3.Location = new Point(220, 3);
            lb3.Margin = new Padding(20, 0, 0, 30);
            lb3.Name = "lb3";
            lb3.Size = new Size(61, 66);
            lb3.TabIndex = 2;
            lb3.Tag = "3";
            lb3.Text = "?";
            lb3.Click += Lb_Click;
            // 
            // lb1
            // 
            lb1.AutoSize = true;
            lb1.Font = new Font("Segoe UI", 36F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lb1.Location = new Point(33, 3);
            lb1.Margin = new Padding(30, 0, 30, 30);
            lb1.Name = "lb1";
            lb1.Size = new Size(36, 66);
            lb1.TabIndex = 0;
            lb1.Tag = "1";
            lb1.Text = "?";
            lb1.TextAlign = ContentAlignment.TopCenter;
            lb1.Click += Lb_Click;
            // 
            // lb2
            // 
            lb2.AutoSize = true;
            lb2.Font = new Font("Segoe UI", 36F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lb2.Location = new Point(122, 3);
            lb2.Margin = new Padding(20, 0, 0, 30);
            lb2.Name = "lb2";
            lb2.Size = new Size(61, 66);
            lb2.TabIndex = 1;
            lb2.Tag = "2";
            lb2.Text = "?";
            lb2.Click += Lb_Click;
            // 
            // lbTurn
            // 
            lbTurn.AutoSize = true;
            lbTurn.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lbTurn.ForeColor = SystemColors.ButtonFace;
            lbTurn.Location = new Point(573, 170);
            lbTurn.Name = "lbTurn";
            lbTurn.Size = new Size(55, 28);
            lbTurn.TabIndex = 2;
            lbTurn.Tag = "1";
            lbTurn.Text = "Turn";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.Orchid;
            ClientSize = new Size(800, 450);
            Controls.Add(lbTurn);
            Controls.Add(tbXOGrid);
            Controls.Add(label1);
            Icon = (Icon)resources.GetObject("$this.Icon");
            Name = "Form1";
            Text = "Tic Tac Toe";
            tbXOGrid.ResumeLayout(false);
            tbXOGrid.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private TableLayoutPanel tbXOGrid;
        private Label lb1;
        private Label lb5;
        private Label lb6;
        private Label lb8;
        private Label lb7;
        private Label label10;
        private Label label9;
        private Label label8;
        private Label lb4;
        private Label label6;
        private Label lb3;
        private Label lb9;
        private Label lb2;
        private Label lbTurn;
    }
}
