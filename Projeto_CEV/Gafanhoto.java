public class Gafanhoto extends Pessoa {
    private String login;
    private int assistido;

    public Gafanhoto(String nome, String sexo, int idade, String login) {
        super(nome, sexo, idade);
        this.assistido = 0;
        this.login = login;
    }
    

    @Override
    public String toString() {
        return 
            "login='" + super.toString() + getLogin() + "'" +
            ", assistido='" + getAssistido();
    }


    public String getLogin() {
        return this.login;
    }
    public void setLogin(String login) {
        this.login = login;
    }

    public int getAssistido() {
        return this.assistido;
    }
    public void setAssistido(int assistido) {
        this.assistido = assistido;
    }
}
