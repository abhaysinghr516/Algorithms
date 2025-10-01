#  Contribution Guidelines

🚀 Welcome! Whether you're fixing a bug, adding a new algorithm, or improving documentation, we're thrilled to have you here. This guide will walk you through the steps to make your contribution smooth and successful.

---

## 🛠️ How to Contribute

1. **Fork the Repository**  
   Create a personal copy of the project by clicking the "Fork" button on GitHub.

2. **Create a New Branch**  
   Use a descriptive name for your branch, like `feat/add-radix-sort-python`.

3. **Add Your Algorithm**  
   - Create a new folder inside the `algorithms/` directory. Use the folder name (e.g., `radix-sort-algorithm`).
   - Add your source code file(s) and a `README.md` explaining the algorithm.
   - Follow the existing coding style and naming conventions for your language.
   - Include clear comments to explain complex logic.

4. **Update `algorithm.json`**  
   This step ensures your algorithm is indexed and visible.

   - Open the `algorithm.json` file in the root directory.
   - If you're adding a new algorithm, create a new object in the array.
   - Add the relative path to your file under the correct language key.

   **Example: Adding a C# implementation for Bubble Sort**

   ```json
   {
     "name": "Bubble Sort Algorithm",
     "slug": "bubble-sort-algorithm",
     "description": "Bubble Sort Algorithm",
     "languages": {
       ".py": [
         "algorithms/bubble-sort-algorithm/BubbleSort.py"
       ],
       ".js": [
         "algorithms/bubble-sort-algorithm/BubbleSort.js"
       ],
       ".java": [
         "algorithms/bubble-sort-algorithm/BubbleSort.java"
       ],
       ".cs": [
         "algorithms/bubble-sort-algorithm/BubbleSort.cs"
       ]
     }
   }
   ```

   ⚠️ **Important:** Be careful not to break the JSON format—check commas, brackets, and indentation.

5. **Test Your Code**  
   Make sure your implementation works correctly and handles edge cases.

6. **Commit and Push**  
   Use a clear, descriptive commit message. Example: `Add radix sort implementation in Python`.

7. **Create a Pull Request**  
   Open a PR from your branch to the main repository. Include a detailed description of your changes.

8. **Code Review**  
   A maintainer will review your PR. Be open to feedback and make necessary adjustments.

---

## ✅ Contribution Checklist

- [ ] Fork the repository
- [ ] Create a new branch
- [ ] Add your algorithm folder and files
- [ ] Update `algorithm.json`
- [ ] Test your code
- [ ] Commit and push changes
- [ ] Create a pull request

---

## 🤝 Code of Conduct

To keep our community welcoming and productive:

- Be respectful and considerate to others.
- Use appropriate language—no offensive or discriminatory remarks.
- Keep discussions focused and constructive.
- Embrace feedback and be open to learning.
