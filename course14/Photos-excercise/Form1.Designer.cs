namespace Photos_excercise
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
            groupBox1 = new GroupBox();
            rbPencil = new RadioButton();
            rbPen = new RadioButton();
            rbBoy = new RadioButton();
            rbGirl = new RadioButton();
            pictureBox1 = new PictureBox();
            groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).BeginInit();
            SuspendLayout();
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(rbPencil);
            groupBox1.Controls.Add(rbPen);
            groupBox1.Controls.Add(rbBoy);
            groupBox1.Controls.Add(rbGirl);
            groupBox1.Location = new Point(79, 382);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(650, 48);
            groupBox1.TabIndex = 0;
            groupBox1.TabStop = false;
            groupBox1.Text = "Choose";
            groupBox1.Enter += groupBox1_Enter;
            // 
            // rbPencil
            // 
            rbPencil.AutoSize = true;
            rbPencil.Location = new Point(446, 18);
            rbPencil.Name = "rbPencil";
            rbPencil.Size = new Size(68, 24);
            rbPencil.TabIndex = 3;
            rbPencil.TabStop = true;
            rbPencil.Text = "Pencil";
            rbPencil.UseVisualStyleBackColor = true;
            rbPencil.CheckedChanged += update_photo;
            // 
            // rbPen
            // 
            rbPen.AutoSize = true;
            rbPen.Location = new Point(324, 18);
            rbPen.Name = "rbPen";
            rbPen.Size = new Size(53, 24);
            rbPen.TabIndex = 2;
            rbPen.TabStop = true;
            rbPen.Text = "Pen";
            rbPen.UseVisualStyleBackColor = true;
            rbPen.CheckedChanged += update_photo;
            // 
            // rbBoy
            // 
            rbBoy.AutoSize = true;
            rbBoy.Location = new Point(200, 18);
            rbBoy.Name = "rbBoy";
            rbBoy.Size = new Size(55, 24);
            rbBoy.TabIndex = 1;
            rbBoy.TabStop = true;
            rbBoy.Text = "Boy";
            rbBoy.UseVisualStyleBackColor = true;
            rbBoy.CheckedChanged += update_photo;
            // 
            // rbGirl
            // 
            rbGirl.AutoSize = true;
            rbGirl.Location = new Point(78, 18);
            rbGirl.Name = "rbGirl";
            rbGirl.Size = new Size(53, 24);
            rbGirl.TabIndex = 0;
            rbGirl.TabStop = true;
            rbGirl.Text = "Girl";
            rbGirl.UseVisualStyleBackColor = true;
            rbGirl.CheckedChanged += update_photo;
            // 
            // pictureBox1
            // 
            pictureBox1.Location = new Point(206, 58);
            pictureBox1.Name = "pictureBox1";
            pictureBox1.Size = new Size(372, 288);
            pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
            pictureBox1.TabIndex = 1;
            pictureBox1.TabStop = false;
            pictureBox1.Click += pictureBox1_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(pictureBox1);
            Controls.Add(groupBox1);
            Name = "Form1";
            Text = "Form1";
            groupBox1.ResumeLayout(false);
            groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)pictureBox1).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private GroupBox groupBox1;
        private RadioButton rbPencil;
        private RadioButton rbPen;
        private RadioButton rbBoy;
        private RadioButton rbGirl;
        private PictureBox pictureBox1;
    }
}
