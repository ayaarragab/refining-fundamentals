namespace RemainingExcercisesInCourse14
{
    partial class Form3
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form3));
            listView1 = new ListView();
            textBox1 = new TextBox();
            lblInfo = new Label();
            lblName = new Label();
            textBox2 = new TextBox();
            btnAdd = new Button();
            btnRemove = new Button();
            btnRemoveAll = new Button();
            BtnAddRandom = new Button();
            imageList1 = new ImageList(components);
            comboBox1 = new ComboBox();
            PName = new ColumnHeader();
            ID = new ColumnHeader();
            SuspendLayout();
            // 
            // listView1
            // 
            listView1.Columns.AddRange(new ColumnHeader[] { PName, ID });
            listView1.Location = new Point(104, 162);
            listView1.Name = "listView1";
            listView1.Size = new Size(564, 229);
            listView1.TabIndex = 0;
            listView1.UseCompatibleStateImageBehavior = false;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(12, 118);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(221, 27);
            textBox1.TabIndex = 1;
            // 
            // lblInfo
            // 
            lblInfo.AutoSize = true;
            lblInfo.Location = new Point(12, 95);
            lblInfo.Name = "lblInfo";
            lblInfo.Size = new Size(24, 20);
            lblInfo.TabIndex = 2;
            lblInfo.Text = "ID";
            // 
            // lblName
            // 
            lblName.AutoSize = true;
            lblName.Location = new Point(12, 42);
            lblName.Name = "lblName";
            lblName.Size = new Size(49, 20);
            lblName.TabIndex = 4;
            lblName.Text = "PName";
            // 
            // textBox2
            // 
            textBox2.Location = new Point(12, 65);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(221, 27);
            textBox2.TabIndex = 3;
            // 
            // btnAdd
            // 
            btnAdd.Location = new Point(252, 118);
            btnAdd.Name = "btnAdd";
            btnAdd.Size = new Size(158, 27);
            btnAdd.TabIndex = 5;
            btnAdd.Text = "Add";
            btnAdd.UseVisualStyleBackColor = true;
            btnAdd.Click += btnAdd_Click;
            // 
            // btnRemove
            // 
            btnRemove.Location = new Point(252, 65);
            btnRemove.Name = "btnRemove";
            btnRemove.Size = new Size(158, 27);
            btnRemove.TabIndex = 6;
            btnRemove.Text = "Remove";
            btnRemove.UseVisualStyleBackColor = true;
            // 
            // btnRemoveAll
            // 
            btnRemoveAll.Location = new Point(416, 118);
            btnRemoveAll.Name = "btnRemoveAll";
            btnRemoveAll.Size = new Size(158, 27);
            btnRemoveAll.TabIndex = 7;
            btnRemoveAll.Text = "Remove All";
            btnRemoveAll.UseVisualStyleBackColor = true;
            // 
            // BtnAddRandom
            // 
            BtnAddRandom.Location = new Point(418, 65);
            BtnAddRandom.Name = "BtnAddRandom";
            BtnAddRandom.Size = new Size(158, 27);
            BtnAddRandom.TabIndex = 8;
            BtnAddRandom.Text = "Add Random";
            BtnAddRandom.UseVisualStyleBackColor = true;
            // 
            // imageList1
            // 
            imageList1.ColorDepth = ColorDepth.Depth32Bit;
            imageList1.ImageStream = (ImageListStreamer)resources.GetObject("imageList1.ImageStream");
            imageList1.TransparentColor = Color.Transparent;
            imageList1.Images.SetKeyName(0, "IMG_5588.JPEG");
            imageList1.Images.SetKeyName(1, "photo_5879643257535402247_y.jpg");
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Items.AddRange(new object[] { "Details", "Large Icons", "Small Icons", "Tile", "List" });
            comboBox1.Location = new Point(603, 71);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(171, 28);
            comboBox1.TabIndex = 9;
            comboBox1.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            // 
            // Form3
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(comboBox1);
            Controls.Add(BtnAddRandom);
            Controls.Add(btnRemoveAll);
            Controls.Add(btnRemove);
            Controls.Add(btnAdd);
            Controls.Add(lblName);
            Controls.Add(textBox2);
            Controls.Add(lblInfo);
            Controls.Add(textBox1);
            Controls.Add(listView1);
            Name = "Form3";
            Text = "Form3";
            Load += Form3_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ListView listView1;
        private TextBox textBox1;
        private Label lblInfo;
        private Label lblName;
        private TextBox textBox2;
        private Button btnAdd;
        private Button btnRemove;
        private Button btnRemoveAll;
        private Button BtnAddRandom;
        private ImageList imageList1;
        private ComboBox comboBox1;
        private ColumnHeader PName;
        private ColumnHeader ID;
    }
}