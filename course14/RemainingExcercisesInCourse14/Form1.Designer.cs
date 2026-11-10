namespace RemainingExcercisesInCourse14
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
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            dateTimePicker1 = new DateTimePicker();
            btnLong = new Button();
            lblShow = new Label();
            btnShort = new Button();
            btnTime = new Button();
            btnDay = new Button();
            btnMonth = new Button();
            btnYear = new Button();
            timer1 = new System.Windows.Forms.Timer(components);
            notifyIcon1 = new NotifyIcon(components);
            button1 = new Button();
            SuspendLayout();
            // 
            // dateTimePicker1
            // 
            dateTimePicker1.Location = new Point(146, 104);
            dateTimePicker1.Name = "dateTimePicker1";
            dateTimePicker1.Size = new Size(287, 27);
            dateTimePicker1.TabIndex = 0;
            // 
            // btnLong
            // 
            btnLong.Location = new Point(23, 280);
            btnLong.Name = "btnLong";
            btnLong.Size = new Size(152, 65);
            btnLong.TabIndex = 1;
            btnLong.Text = "Show Long";
            btnLong.UseVisualStyleBackColor = true;
            btnLong.Click += btnLong_Click;
            // 
            // lblShow
            // 
            lblShow.AutoSize = true;
            lblShow.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 0);
            lblShow.Location = new Point(492, 162);
            lblShow.Name = "lblShow";
            lblShow.Size = new Size(97, 41);
            lblShow.TabIndex = 2;
            lblShow.Text = "label1";
            // 
            // btnShort
            // 
            btnShort.Location = new Point(223, 280);
            btnShort.Name = "btnShort";
            btnShort.Size = new Size(152, 65);
            btnShort.TabIndex = 3;
            btnShort.Text = "Show Short";
            btnShort.UseVisualStyleBackColor = true;
            btnShort.Click += btnShort_Click;
            // 
            // btnTime
            // 
            btnTime.Location = new Point(408, 280);
            btnTime.Name = "btnTime";
            btnTime.Size = new Size(152, 65);
            btnTime.TabIndex = 4;
            btnTime.Text = "Show Time";
            btnTime.UseVisualStyleBackColor = true;
            btnTime.Click += btnTime_Click;
            // 
            // btnDay
            // 
            btnDay.Location = new Point(588, 280);
            btnDay.Name = "btnDay";
            btnDay.Size = new Size(152, 65);
            btnDay.TabIndex = 5;
            btnDay.Text = "Show Day";
            btnDay.UseVisualStyleBackColor = true;
            btnDay.Click += btnDay_Click;
            // 
            // btnMonth
            // 
            btnMonth.Location = new Point(223, 373);
            btnMonth.Name = "btnMonth";
            btnMonth.Size = new Size(152, 65);
            btnMonth.TabIndex = 6;
            btnMonth.Text = "Show Month";
            btnMonth.UseVisualStyleBackColor = true;
            btnMonth.Click += btnMonth_Click;
            // 
            // btnYear
            // 
            btnYear.Location = new Point(408, 373);
            btnYear.Name = "btnYear";
            btnYear.Size = new Size(152, 65);
            btnYear.TabIndex = 7;
            btnYear.Text = "Show Year";
            btnYear.UseVisualStyleBackColor = true;
            btnYear.Click += btnYear_Click;
            // 
            // timer1
            // 
            timer1.Enabled = true;
            timer1.Interval = 1000;
            timer1.Tick += ActWhenTick;
            // 
            // notifyIcon1
            // 
            notifyIcon1.BalloonTipIcon = ToolTipIcon.Info;
            notifyIcon1.BalloonTipText = "Hey this is your notification from a desktop app!";
            notifyIcon1.Icon = (Icon)resources.GetObject("notifyIcon1.Icon");
            notifyIcon1.Visible = true;
            // 
            // button1
            // 
            button1.Location = new Point(33, 373);
            button1.Name = "button1";
            button1.Size = new Size(152, 65);
            button1.TabIndex = 8;
            button1.Text = "Show Notification";
            button1.UseVisualStyleBackColor = true;
            button1.Click += show_noti;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(button1);
            Controls.Add(btnYear);
            Controls.Add(btnMonth);
            Controls.Add(btnDay);
            Controls.Add(btnTime);
            Controls.Add(btnShort);
            Controls.Add(lblShow);
            Controls.Add(btnLong);
            Controls.Add(dateTimePicker1);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private DateTimePicker dateTimePicker1;
        private Button btnLong;
        private Label lblShow;
        private Button btnShort;
        private Button btnTime;
        private Button btnDay;
        private Button btnMonth;
        private Button btnYear;
        private System.Windows.Forms.Timer timer1;
        private NotifyIcon notifyIcon1;
        private Button button1;
    }
}
