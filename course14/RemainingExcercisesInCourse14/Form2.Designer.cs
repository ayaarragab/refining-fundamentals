namespace RemainingExcercisesInCourse14
{
    partial class Form2
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
            TreeNode treeNode1 = new TreeNode("1");
            TreeNode treeNode2 = new TreeNode("2");
            TreeNode treeNode3 = new TreeNode("Al-Azhar Park", new TreeNode[] { treeNode1, treeNode2 });
            TreeNode treeNode4 = new TreeNode("1");
            TreeNode treeNode5 = new TreeNode("2");
            TreeNode treeNode6 = new TreeNode("Graduation", new TreeNode[] { treeNode4, treeNode5 });
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form2));
            treeView1 = new TreeView();
            imageList1 = new ImageList(components);
            progressBar1 = new ProgressBar();
            label1 = new Label();
            timer1 = new System.Windows.Forms.Timer(components);
            SuspendLayout();
            // 
            // treeView1
            // 
            treeView1.ImageIndex = 0;
            treeView1.ImageList = imageList1;
            treeView1.Location = new Point(22, 39);
            treeView1.Name = "treeView1";
            treeNode1.Name = "Node0";
            treeNode1.Text = "1";
            treeNode2.Name = "Node1";
            treeNode2.Text = "2";
            treeNode3.Name = "azharNode";
            treeNode3.Text = "Al-Azhar Park";
            treeNode4.Name = "Node2";
            treeNode4.Text = "1";
            treeNode5.Name = "Node4";
            treeNode5.Text = "2";
            treeNode6.ImageIndex = 1;
            treeNode6.Name = "gradNode";
            treeNode6.Text = "Graduation";
            treeView1.Nodes.AddRange(new TreeNode[] { treeNode3, treeNode6 });
            treeView1.SelectedImageIndex = 0;
            treeView1.Size = new Size(371, 282);
            treeView1.TabIndex = 0;
            treeView1.AfterSelect += treeView1_AfterSelect;
            // 
            // imageList1
            // 
            imageList1.ColorDepth = ColorDepth.Depth32Bit;
            imageList1.ImageStream = (ImageListStreamer)resources.GetObject("imageList1.ImageStream");
            imageList1.TransparentColor = Color.Transparent;
            imageList1.Images.SetKeyName(0, "IMG_5588.JPEG");
            imageList1.Images.SetKeyName(1, "photo_5879643257535402247_y.jpg");
            // 
            // progressBar1
            // 
            progressBar1.Location = new Point(447, 274);
            progressBar1.Name = "progressBar1";
            progressBar1.Size = new Size(282, 37);
            progressBar1.TabIndex = 1;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 20F);
            label1.Location = new Point(532, 216);
            label1.Name = "label1";
            label1.Size = new Size(109, 46);
            label1.TabIndex = 2;
            label1.Text = "label1";
            // 
            // timer1
            // 
            timer1.Enabled = true;
            timer1.Interval = 500;
            timer1.Tick += timer1_Tick;
            // 
            // Form2
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(label1);
            Controls.Add(progressBar1);
            Controls.Add(treeView1);
            Name = "Form2";
            Text = "Form2";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        public TreeView treeView1;
        private ImageList imageList1;
        private ProgressBar progressBar1;
        private Label label1;
        private System.Windows.Forms.Timer timer1;
    }
}