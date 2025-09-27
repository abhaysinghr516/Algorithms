# Algorithm Collection Website

A clean, minimal website showcasing algorithm implementations across multiple programming languages.

## Deployment Instructions

### GitHub Pages

1. Push the `website` folder contents to your GitHub repository
2. Go to repository Settings > Pages
3. Select "Deploy from a branch"
4. Choose `main` branch and `/ (root)` folder
5. Your site will be available at `https://yourusername.github.io/repository-name`

### Vercel

1. Install Vercel CLI: `npm i -g vercel`
2. Navigate to the website folder: `cd website`
3. Run: `vercel`
4. Follow the prompts to deploy
5. Your site will be available at the provided Vercel URL

### Alternative Vercel Deployment

1. Go to [vercel.com](https://vercel.com)
2. Import your GitHub repository
3. Set the root directory to `website`
4. Deploy

## Files Structure

- `index.html` - Main HTML file
- `styles.css` - Stylesheet
- `script.js` - JavaScript functionality
- `algorithms.json` - Algorithm data
- `vercel.json` - Vercel configuration
- `.nojekyll` - GitHub Pages configuration
- `404.html` - Custom 404 page

## Adding New Algorithms

To add new algorithms to the website, update the `algorithms.json` file with the new algorithm data following the existing format.
