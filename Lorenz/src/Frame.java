import java.awt.*;
import javax.swing.*;

public class Frame extends JFrame {
    Frame() {
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(2160, 3840);
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }

    public void paint(Graphics g) {
        float x = 0.1f, y = 0.0f, z = 0.0f, dx = 0.0f, dy = 0.0f, dz = 0.0f, dt = 0.001f, t = 0.0f, a = 10.0f, b = 28.0f, c = 8.0f / 3.0f;
        
        g.setColor(Color.BLACK);
        while(t < 110.0f) {
            dx = a * (y - x) * dt;
            dy = (x * (b - z) - y) * dt;
            dz = (x * y - c * z) * dt;
    
            x = x + dx;
            y = y + dy;
            z = z + dz;
            t = t + dt;

            g.drawLine((int) (x * 10) + 250, (int) (y * 10) + 350, (int) (x * 10) + 250, (int) (y * 10) + 350);
            g.drawLine((int) (x * 10) + 650, (int) (z * 10) + 200, (int) (x * 10) + 650, (int) (z * 10) + 200);
            g.drawLine((int) (y * 10) + 1100, (int) (z * 10) + 200, (int) (y * 10) + 1100, (int) (z * 10) + 200);
            //g.drawLine((int) (x * 13) + 650, (int) (z * 13) + 200, (int) (x * 13) + 650, (int) (z * 13) + 200);
        }
    }
}
