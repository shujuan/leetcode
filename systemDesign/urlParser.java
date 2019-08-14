import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class HtmlParser {
    /**
     * @param content source code
     * @return a list of links
     */
    private static final String HTML_HREF_TAG_PATTERN="\\s*(?i)href\\s*=\\s*(\"|')+([^\"'>\\s]*)";
    public List<String> parseUrls(String content) {
        // Write your code here
        List<String> links=new ArrayList<String>();
        Pattern p=Pattern.compile(HTML_HREF_TAG_PATTERN,Pattern.CASE_INSENSITIVE);
        Matcher m=p.matcher(content);
        String url=null;
        while(m.find()){
            url=m.group(2);
            if(url.length()==0||url.startsWith("#")) continue;
            links.add(url);
        }
        return links;
    }
}
