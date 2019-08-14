/**
 * public class HtmlHelper {
 *     public static List<String> parseUrls(String url);
 *         // Get all urls from a webpage of given url. 
 * }
 */
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicLong;
import java.lang.Thread;
import java.net.*;
import java.io.*;

public class Solution {
    /**
     * @param url: a url of root page
     * @return: all urls
     */
    BlockingQueue<String> urlPool = new LinkedBlockingQueue<String>();
    Set<String>urls = new HashSet<String>();
    AtomicLong finished = new AtomicLong(0);
    
    public List<String> crawler(String url) {
        // write your code here
        try {
            urlPool.put(url);
        } catch (InterruptedException  e){
                
        }
        CrawlerThread[] workers = new CrawlerThread[7];
        for(int i=0; i<7; i++) {
            workers[i] = new CrawlerThread();
            workers[i].start();
        }
        
        try{
            while(urlPool.size() !=0 && finished.get() !=0){
                Thread.sleep(10);
            }
        } catch(InterruptedException e){
            
        }
        
        for(int i=0; i<7; i++) {
            workers[i].stop();
        }
        
        return new ArrayList<String>(urls);
        
        
        
    }
    

        
    private class CrawlerThread extends Thread{
        public void run() {
            while(urlPool.size() == 0);
            String url=null;
            String domain = null;
            //url fetch
             try{
                url= urlPool.take();
                
            }catch(Exception e){
               
            }
           
            finished.incrementAndGet();
            try{
                URL netUrl= new URL(url);
                domain=netUrl.getHost();
            }catch(MalformedURLException e){
                
            }
            //url parser
            if(!urls.contains(url) && domain.endsWith("wikipedia.org")) {
                urls.add(url);
                List<String> tmp = HtmlHelper.parseUrls(url);
                
                for(String u : tmp) {
                    
                    try {
                        urlPool.put(u);
                    } catch (InterruptedException  e){
                        
                    }
                }
                finished.decrementAndGet();
            }
            
            
            
        }    
            

    }
}
