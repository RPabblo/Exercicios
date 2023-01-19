public class App {
    public static void main(String[] args) throws Exception {
        Video videos[] = new Video[3];

        videos[0] = new Video("Aula 1");
        videos[1] = new Video("Aula 2");
        videos[1] = new Video("Aula 3");

        Gafanhoto gafanhoto = new Gafanhoto("Maria", "F", 22, "admin");

        System.out.println(videos[0].toString() + "\n");
        System.out.println(gafanhoto.toString() + "\n");
    }
}

