namespace FirstWindowsFormsApp
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
            label1 = new Label();
            textBox1 = new TextBox();
            label2 = new Label();
            textBox2 = new TextBox();
            button1 = new Button();
            label3 = new Label();
            button2 = new Button();
            button3 = new Button();
            label4 = new Label();
            checkBox1 = new CheckBox();
            checkBox2 = new CheckBox();
            label5 = new Label();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(54, 65);
            label1.Name = "label1";
            label1.Size = new Size(76, 20);
            label1.TabIndex = 0;
            label1.Text = "Full Name";
            label1.TextAlign = ContentAlignment.MiddleCenter;
            label1.Click += label1_Click;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(54, 88);
            textBox1.Name = "textBox1";
            textBox1.ScrollBars = ScrollBars.Horizontal;
            textBox1.Size = new Size(187, 27);
            textBox1.TabIndex = 0;
            textBox1.TextChanged += textBox1_TextChanged;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(54, 142);
            label2.Name = "label2";
            label2.Size = new Size(70, 20);
            label2.TabIndex = 2;
            label2.Text = "Password";
            label2.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // textBox2
            // 
            textBox2.Location = new Point(54, 165);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(187, 27);
            textBox2.TabIndex = 2;
            // 
            // button1
            // 
            button1.BackColor = SystemColors.ButtonHighlight;
            button1.FlatAppearance.MouseDownBackColor = Color.FromArgb(192, 255, 192);
            button1.FlatAppearance.MouseOverBackColor = Color.FromArgb(0, 192, 192);
            button1.FlatStyle = FlatStyle.Flat;
            button1.Location = new Point(54, 334);
            button1.Name = "button1";
            button1.Size = new Size(105, 42);
            button1.TabIndex = 5;
            button1.Text = "Submit";
            button1.UseVisualStyleBackColor = false;
            button1.Click += preview_login_succ;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(54, 396);
            label3.Name = "label3";
            label3.Size = new Size(50, 20);
            label3.TabIndex = 5;
            label3.Text = "label3";
            // 
            // button2
            // 
            button2.BackColor = SystemColors.ButtonHighlight;
            button2.FlatAppearance.MouseDownBackColor = Color.FromArgb(255, 192, 192);
            button2.FlatAppearance.MouseOverBackColor = Color.FromArgb(255, 128, 128);
            button2.FlatStyle = FlatStyle.Flat;
            button2.Location = new Point(181, 334);
            button2.Name = "button2";
            button2.Size = new Size(105, 42);
            button2.TabIndex = 4;
            button2.Text = "Disable All";
            button2.UseVisualStyleBackColor = false;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.BackColor = SystemColors.ButtonHighlight;
            button3.FlatAppearance.MouseDownBackColor = Color.FromArgb(255, 192, 192);
            button3.FlatAppearance.MouseOverBackColor = Color.FromArgb(255, 128, 128);
            button3.FlatStyle = FlatStyle.Flat;
            button3.Location = new Point(308, 334);
            button3.Name = "button3";
            button3.Size = new Size(105, 42);
            button3.TabIndex = 3;
            button3.Text = "Hide All";
            button3.UseVisualStyleBackColor = false;
            button3.Click += button3_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.BackColor = SystemColors.ButtonFace;
            label4.Font = new Font("Segoe Script", 19.8000011F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label4.ForeColor = Color.SteelBlue;
            label4.Location = new Point(174, 9);
            label4.Name = "label4";
            label4.Size = new Size(444, 57);
            label4.TabIndex = 8;
            label4.Text = "Full Name will be here";
            // 
            // checkBox1
            // 
            checkBox1.AutoSize = true;
            checkBox1.Location = new Point(58, 242);
            checkBox1.Name = "checkBox1";
            checkBox1.Size = new Size(49, 24);
            checkBox1.TabIndex = 9;
            checkBox1.Text = "C#";
            checkBox1.UseVisualStyleBackColor = true;
            // 
            // checkBox2
            // 
            checkBox2.AutoSize = true;
            checkBox2.Location = new Point(58, 272);
            checkBox2.Name = "checkBox2";
            checkBox2.Size = new Size(60, 24);
            checkBox2.TabIndex = 10;
            checkBox2.Text = "C++";
            checkBox2.UseVisualStyleBackColor = true;
            checkBox2.CheckedChanged += checkBox2_CheckedChanged;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(54, 219);
            label5.Name = "label5";
            label5.Size = new Size(175, 20);
            label5.TabIndex = 11;
            label5.Text = "Programming Languages";
            label5.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.ActiveCaption;
            ClientSize = new Size(800, 450);
            Controls.Add(label5);
            Controls.Add(checkBox2);
            Controls.Add(checkBox1);
            Controls.Add(label4);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(label3);
            Controls.Add(button1);
            Controls.Add(textBox2);
            Controls.Add(label2);
            Controls.Add(textBox1);
            Controls.Add(label1);
            ForeColor = SystemColors.Desktop;
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private TextBox textBox1;
        private Label label2;
        private TextBox textBox2;
        private Button button1;
        private Label label3;
        private Button button2;
        private Button button3;
        private Label label4;
        private CheckBox checkBox1;
        private CheckBox checkBox2;
        private Label label5;
    }
}
