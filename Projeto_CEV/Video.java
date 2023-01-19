public class Video implements AcoesVideo {
    private String titulo;
    private int avaliacao, views, curtidas;
    private boolean reproduzindo;


    public Video(String titulo) {
        this.titulo = titulo;
        this.avaliacao = 1;
        this.views = 0;
        this.curtidas = 0;
        this.reproduzindo = false;
    }

    @Override
    public void play() {
        if(!isReproduzindo()) {
            System.out.println("Reproduzindo...");
            setReproduzindo(true);
        }
    }
    @Override
    public void pause() {
        if(isReproduzindo()) {
            setReproduzindo(false);
            System.out.println("Pausando...");
        }
    }
    @Override
    public void like() {
        setCurtidas(getCurtidas() + 1);
    }
    @Override
    public String toString() {
        return 
            " titulo='" + getTitulo() + "'" +
            ", avaliacao='" + getAvaliacao() + "'" +
            ", views='" + getViews() + "'" +
            ", curtidas='" + getCurtidas() + "'" +
            ", reproduzindo='" + isReproduzindo();
    }

    public String getTitulo() {
        return this.titulo;
    }
    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public int getAvaliacao() {
        return this.avaliacao;
    }
    public void setAvaliacao(int avaliacao) {
        this.avaliacao = avaliacao;
    }

    public int getViews() {
        return this.views;
    }
    public void setViews(int views) {
        this.views = views;
    }

    public int getCurtidas() {
        return this.curtidas;
    }
    public void setCurtidas(int curtidas) {
        this.curtidas = curtidas;
    }

    public boolean isReproduzindo() {
        return this.reproduzindo;
    }
    public void setReproduzindo(boolean reproduzindo) {
        this.reproduzindo = reproduzindo;
    }
}
