import java.util.*;
class Conway{
    int Min=1;
    int Max_row=50;
    int Max_col=100;
    int initialise=1000;

    int [][] grid = new int[Max_row+1][Max_col+1];

    public Conway(){
        for(int i=0;i<Max_row+1;i++){
            for(int j=0;j<Max_col+1;j++){
                grid[i][j]=0;
            }
        }
        
        
        for(int i=0;i<initialise;i++){
            int k = Min + (int)(Math.random() * ((Max_row - Min) + 1));
            int l = Min + (int)(Math.random() * ((Max_col - Min) + 1));

            grid[k][l] = 1;
        }
    }

    public void life_death(){
        ArrayList<int[]> deaths = new ArrayList<>();
        ArrayList<int[]> newborns = new ArrayList<>();

        for(int i=1;i<Max_row;i++){     // Middle Matrix
            for(int j=1;j<Max_col;j++){
                
                int count=0;

                if(grid[i+1][j]==1) count+=1; //Right
                if(grid[i-1][j]==1) count+=1; //Left
                if(grid[i][j-1]==1) count+=1; //Up
                if(grid[i][j+1]==1) count+=1; //Down
                if(grid[i+1][j-1]==1) count+=1; //Up-right
                if(grid[i-1][j-1]==1) count+=1; //Up-left
                if(grid[i+1][j+1]==1) count+=1; //Down-right
                if(grid[i-1][j+1]==1) count+=1; //Down-left
                
                if(grid[i][j] == 1 && (count<2 || count>3)){
                    deaths.add(new int[]{i,j});   
                }
                else if(grid[i][j] == 0 && count == 3){
                    newborns.add(new int[]{i,j});
                }
    
            }
        }

        for(int i=0;i<deaths.size();i++){
            grid[deaths.get(i)[0]][deaths.get(i)[1]] = 0;
        }
        for(int i=0;i<newborns.size();i++){
            grid[newborns.get(i)[0]][newborns.get(i)[1]] =1;
        }
    }

    void print(){
        for(int i=0;i<Max_row;i++){
            for(int j=0;j<Max_col;j++){
                if(grid[i][j] == 0) System.out.print(" ");
                else System.out.print("@");
            }
            System.out.println();
            
        }
    }

    public static void main(String[]args){
        Conway c = new Conway();
        
        for(int i=0;i<20;i++){ 
            c.print();
            c.life_death();
            try
            {
                Thread.sleep(500);
            }
            catch(InterruptedException ex)
            {
                Thread.currentThread().interrupt();
            }
            System.out.print("\033[H\033[2J");  
            System.out.flush();
            
        }
    }
    
}
