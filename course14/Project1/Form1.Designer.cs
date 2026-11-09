namespace Project1
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
            gbSize = new GroupBox();
            rbLarge = new RadioButton();
            rbMedium = new RadioButton();
            rbSmall = new RadioButton();
            gbToppings = new GroupBox();
            chTom = new CheckBox();
            chMush = new CheckBox();
            chExtrach = new CheckBox();
            gbCrustType = new GroupBox();
            rbThick = new RadioButton();
            rbThin = new RadioButton();
            gbInOrOut = new GroupBox();
            rbEatOut = new RadioButton();
            rbEatIn = new RadioButton();
            gbOrderSummary = new GroupBox();
            lbToppings = new Label();
            lbTotalPrice = new Label();
            lbWhereToEat = new Label();
            lbCrustType = new Label();
            lbSize = new Label();
            gbSize.SuspendLayout();
            gbToppings.SuspendLayout();
            gbCrustType.SuspendLayout();
            gbInOrOut.SuspendLayout();
            gbOrderSummary.SuspendLayout();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Showcard Gothic", 36F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label1.ForeColor = Color.Red;
            label1.Location = new Point(115, 9);
            label1.Name = "label1";
            label1.Size = new Size(561, 74);
            label1.TabIndex = 0;
            label1.Text = "Make your Pizza";
            // 
            // gbSize
            // 
            gbSize.Controls.Add(rbLarge);
            gbSize.Controls.Add(rbMedium);
            gbSize.Controls.Add(rbSmall);
            gbSize.Location = new Point(22, 107);
            gbSize.Name = "gbSize";
            gbSize.Size = new Size(119, 127);
            gbSize.TabIndex = 1;
            gbSize.TabStop = false;
            gbSize.Text = "Size";
            gbSize.Enter += groupBox1_Enter;
            // 
            // rbLarge
            // 
            rbLarge.AutoSize = true;
            rbLarge.Location = new Point(6, 86);
            rbLarge.Name = "rbLarge";
            rbLarge.Size = new Size(67, 24);
            rbLarge.TabIndex = 2;
            rbLarge.TabStop = true;
            rbLarge.Tag = "30";
            rbLarge.Text = "Large";
            rbLarge.UseVisualStyleBackColor = true;
            rbLarge.CheckedChanged += Update_Size_Label;
            // 
            // rbMedium
            // 
            rbMedium.AutoSize = true;
            rbMedium.Location = new Point(6, 56);
            rbMedium.Name = "rbMedium";
            rbMedium.Size = new Size(85, 24);
            rbMedium.TabIndex = 1;
            rbMedium.TabStop = true;
            rbMedium.Tag = "20";
            rbMedium.Text = "Medium";
            rbMedium.UseVisualStyleBackColor = true;
            rbMedium.CheckedChanged += Update_Size_Label;
            // 
            // rbSmall
            // 
            rbSmall.AutoSize = true;
            rbSmall.Location = new Point(6, 26);
            rbSmall.Name = "rbSmall";
            rbSmall.Size = new Size(67, 24);
            rbSmall.TabIndex = 0;
            rbSmall.TabStop = true;
            rbSmall.Tag = "10";
            rbSmall.Text = "Small";
            rbSmall.UseVisualStyleBackColor = true;
            rbSmall.CheckedChanged += Update_Size_Label;
            // 
            // gbToppings
            // 
            gbToppings.Controls.Add(chTom);
            gbToppings.Controls.Add(chMush);
            gbToppings.Controls.Add(chExtrach);
            gbToppings.Location = new Point(211, 107);
            gbToppings.Name = "gbToppings";
            gbToppings.Size = new Size(128, 127);
            gbToppings.TabIndex = 3;
            gbToppings.TabStop = false;
            gbToppings.Text = "Toppings";
            // 
            // chTom
            // 
            chTom.AutoSize = true;
            chTom.Location = new Point(5, 86);
            chTom.Name = "chTom";
            chTom.Size = new Size(96, 24);
            chTom.TabIndex = 2;
            chTom.Tag = "30";
            chTom.Text = "Tomateos";
            chTom.UseVisualStyleBackColor = true;
            chTom.CheckedChanged += updateToppings;
            // 
            // chMush
            // 
            chMush.AutoSize = true;
            chMush.Location = new Point(5, 56);
            chMush.Name = "chMush";
            chMush.Size = new Size(102, 24);
            chMush.TabIndex = 1;
            chMush.Tag = "20";
            chMush.Text = "Mushroom";
            chMush.UseVisualStyleBackColor = true;
            chMush.CheckedChanged += updateToppings;
            // 
            // chExtrach
            // 
            chExtrach.AutoSize = true;
            chExtrach.Location = new Point(5, 29);
            chExtrach.Name = "chExtrach";
            chExtrach.Size = new Size(115, 24);
            chExtrach.TabIndex = 0;
            chExtrach.Tag = "10";
            chExtrach.Text = "Extra Cheese";
            chExtrach.UseVisualStyleBackColor = true;
            chExtrach.CheckedChanged += updateToppings;
            // 
            // gbCrustType
            // 
            gbCrustType.Controls.Add(rbThick);
            gbCrustType.Controls.Add(rbThin);
            gbCrustType.Location = new Point(22, 259);
            gbCrustType.Name = "gbCrustType";
            gbCrustType.Size = new Size(119, 127);
            gbCrustType.TabIndex = 3;
            gbCrustType.TabStop = false;
            gbCrustType.Text = "Crust Type";
            // 
            // rbThick
            // 
            rbThick.AutoSize = true;
            rbThick.Location = new Point(6, 56);
            rbThick.Name = "rbThick";
            rbThick.Size = new Size(85, 24);
            rbThick.TabIndex = 1;
            rbThick.TabStop = true;
            rbThick.Tag = "20";
            rbThick.Text = "Medium";
            rbThick.UseVisualStyleBackColor = true;
            // 
            // rbThin
            // 
            rbThin.AutoSize = true;
            rbThin.Location = new Point(6, 26);
            rbThin.Name = "rbThin";
            rbThin.Size = new Size(58, 24);
            rbThin.TabIndex = 0;
            rbThin.TabStop = true;
            rbThin.Tag = "10";
            rbThin.Text = "Thin";
            rbThin.UseVisualStyleBackColor = true;
            // 
            // gbInOrOut
            // 
            gbInOrOut.Controls.Add(rbEatOut);
            gbInOrOut.Controls.Add(rbEatIn);
            gbInOrOut.Location = new Point(211, 259);
            gbInOrOut.Name = "gbInOrOut";
            gbInOrOut.Size = new Size(119, 127);
            gbInOrOut.TabIndex = 4;
            gbInOrOut.TabStop = false;
            gbInOrOut.Text = "Where To Eat";
            // 
            // rbEatOut
            // 
            rbEatOut.AutoSize = true;
            rbEatOut.Location = new Point(6, 56);
            rbEatOut.Name = "rbEatOut";
            rbEatOut.Size = new Size(104, 24);
            rbEatOut.TabIndex = 1;
            rbEatOut.TabStop = true;
            rbEatOut.Tag = "20";
            rbEatOut.Text = "Take Home";
            rbEatOut.UseVisualStyleBackColor = true;
            rbEatOut.CheckedChanged += update_eat_where;
            // 
            // rbEatIn
            // 
            rbEatIn.AutoSize = true;
            rbEatIn.Location = new Point(6, 26);
            rbEatIn.Name = "rbEatIn";
            rbEatIn.Size = new Size(67, 24);
            rbEatIn.TabIndex = 0;
            rbEatIn.TabStop = true;
            rbEatIn.Tag = "10";
            rbEatIn.Text = "Eat In";
            rbEatIn.UseVisualStyleBackColor = true;
            rbEatIn.CheckedChanged += update_eat_where;
            // 
            // gbOrderSummary
            // 
            gbOrderSummary.Controls.Add(lbToppings);
            gbOrderSummary.Controls.Add(lbTotalPrice);
            gbOrderSummary.Controls.Add(lbWhereToEat);
            gbOrderSummary.Controls.Add(lbCrustType);
            gbOrderSummary.Controls.Add(lbSize);
            gbOrderSummary.Location = new Point(432, 109);
            gbOrderSummary.Name = "gbOrderSummary";
            gbOrderSummary.Size = new Size(315, 270);
            gbOrderSummary.TabIndex = 5;
            gbOrderSummary.TabStop = false;
            gbOrderSummary.Text = "Order Sumary";
            // 
            // lbToppings
            // 
            lbToppings.AutoSize = true;
            lbToppings.Location = new Point(17, 180);
            lbToppings.Name = "lbToppings";
            lbToppings.Size = new Size(73, 20);
            lbToppings.TabIndex = 4;
            lbToppings.Tag = "0";
            lbToppings.Text = "Toppings:";
            // 
            // lbTotalPrice
            // 
            lbTotalPrice.AutoSize = true;
            lbTotalPrice.Location = new Point(17, 224);
            lbTotalPrice.Name = "lbTotalPrice";
            lbTotalPrice.Size = new Size(85, 20);
            lbTotalPrice.TabIndex = 3;
            lbTotalPrice.Tag = "0";
            lbTotalPrice.Text = "Total Price: ";
            lbTotalPrice.Click += label2_Click;
            // 
            // lbWhereToEat
            // 
            lbWhereToEat.AutoSize = true;
            lbWhereToEat.Location = new Point(17, 135);
            lbWhereToEat.Name = "lbWhereToEat";
            lbWhereToEat.Size = new Size(104, 20);
            lbWhereToEat.TabIndex = 2;
            lbWhereToEat.Text = "Where To Eat: ";
            // 
            // lbCrustType
            // 
            lbCrustType.AutoSize = true;
            lbCrustType.Location = new Point(17, 83);
            lbCrustType.Name = "lbCrustType";
            lbCrustType.Size = new Size(84, 20);
            lbCrustType.TabIndex = 1;
            lbCrustType.Text = "Crust Type: ";
            // 
            // lbSize
            // 
            lbSize.AutoSize = true;
            lbSize.Location = new Point(17, 31);
            lbSize.Name = "lbSize";
            lbSize.Size = new Size(43, 20);
            lbSize.TabIndex = 0;
            lbSize.Text = "Size: ";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(gbOrderSummary);
            Controls.Add(gbInOrOut);
            Controls.Add(gbCrustType);
            Controls.Add(gbToppings);
            Controls.Add(gbSize);
            Controls.Add(label1);
            Icon = (Icon)resources.GetObject("$this.Icon");
            Name = "Form1";
            Text = "Pizza Order";
            Load += Form1_Load;
            gbSize.ResumeLayout(false);
            gbSize.PerformLayout();
            gbToppings.ResumeLayout(false);
            gbToppings.PerformLayout();
            gbCrustType.ResumeLayout(false);
            gbCrustType.PerformLayout();
            gbInOrOut.ResumeLayout(false);
            gbInOrOut.PerformLayout();
            gbOrderSummary.ResumeLayout(false);
            gbOrderSummary.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label1;
        private GroupBox gbSize;
        private RadioButton rbSmall;
        private RadioButton rbMedium;
        private RadioButton rbLarge;
        private GroupBox gbToppings;
        private CheckBox chMush;
        private CheckBox chExtrach;
        private CheckBox chTom;
        private GroupBox gbCrustType;
        private RadioButton radioButton1;
        private RadioButton rbThin;
        private RadioButton rbThick;
        private GroupBox gbInOrOut;
        private RadioButton rbEatOut;
        private RadioButton rbEatIn;
        private GroupBox gbOrderSummary;
        private Label lbTotalPrice;
        private Label lbWhereToEat;
        private Label lbCrustType;
        private Label lbSize;
        private Label lbToppings;
    }
}
